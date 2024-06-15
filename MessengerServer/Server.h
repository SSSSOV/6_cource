#pragma once
#include <iostream>
#include <string>
#include <cliext/vector>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;
using namespace System::IO;

public ref class Server {
private:
    TcpListener^ server;
    cliext::vector<TcpClient^> clients;

public:
    Server() {
        server = gcnew TcpListener(IPAddress::Any, 8080);
        server->Start();
        Console::WriteLine("Server started...");

        Task::Run(gcnew Action(this, &Server::AcceptClients));
    }

    void AcceptClients() {
        while (true) {
            TcpClient^ client = server->AcceptTcpClient();
            clients.push_back(client);
            Console::WriteLine("Client connected...");

            Task::Factory->StartNew(gcnew Action<Object^>(this, &Server::HandleClient), client);
        }
    }

    void HandleClient(Object^ clientObj) {
        TcpClient^ client = (TcpClient^)clientObj;
        NetworkStream^ stream = client->GetStream();
        StreamReader^ reader = gcnew StreamReader(stream);
        StreamWriter^ writer = gcnew StreamWriter(stream);
        writer->AutoFlush = true;

        while (true) {
            String^ message = reader->ReadLine();
            if (message == nullptr) break;

            Console::WriteLine("(Received) " + message);
            BroadcastMessage(message, client);
        }

        client->Close();
    }

    void BroadcastMessage(String^ message, TcpClient^ sender) {
        for each (TcpClient ^ client in clients) {
            if (client != sender) {
                NetworkStream^ stream = client->GetStream();
                StreamWriter^ writer = gcnew StreamWriter(stream);
                writer->AutoFlush = true;
                writer->WriteLine(message);
            }
        }
    }
};

int main(array<System::String^>^ args) {
    Server^ server = gcnew Server();
    Console::ReadLine();
    return 0;
}


