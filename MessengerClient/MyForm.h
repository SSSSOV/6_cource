#pragma once
#include <iostream>
#include <string>
#include <cliext/vector>

namespace MessengerClient {

	using namespace System;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Text;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;
	using namespace System::IO;
	using namespace System::Windows::Forms;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		TcpClient^ client;
		StreamReader^ reader;

	private: System::Windows::Forms::TextBox^ textBoxMessage;
	private: System::Windows::Forms::Button^ buttonSend;
	private: System::Windows::Forms::ListBox^ listBoxHistory;
	private: System::Windows::Forms::Button^ buttonConnect;
	private: System::Windows::Forms::TextBox^ textBoxUsername;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBoxConnect;
	private: System::Windows::Forms::GroupBox^ groupBoxMessenger;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;



		   StreamWriter^ writer;

	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxMessage = (gcnew System::Windows::Forms::TextBox());
			this->buttonSend = (gcnew System::Windows::Forms::Button());
			this->listBoxHistory = (gcnew System::Windows::Forms::ListBox());
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->textBoxUsername = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBoxConnect = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxMessenger = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBoxConnect->SuspendLayout();
			this->groupBoxMessenger->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBoxMessage
			// 
			this->textBoxMessage->Location = System::Drawing::Point(6, 47);
			this->textBoxMessage->Name = L"textBoxMessage";
			this->textBoxMessage->Size = System::Drawing::Size(279, 20);
			this->textBoxMessage->TabIndex = 0;
			// 
			// buttonSend
			// 
			this->buttonSend->Location = System::Drawing::Point(210, 73);
			this->buttonSend->Name = L"buttonSend";
			this->buttonSend->Size = System::Drawing::Size(75, 23);
			this->buttonSend->TabIndex = 1;
			this->buttonSend->Text = L"Send";
			this->buttonSend->UseVisualStyleBackColor = true;
			this->buttonSend->Click += gcnew System::EventHandler(this, &MyForm::SendButton_Click);
			// 
			// listBoxHistory
			// 
			this->listBoxHistory->FormattingEnabled = true;
			this->listBoxHistory->Location = System::Drawing::Point(6, 100);
			this->listBoxHistory->Name = L"listBoxHistory";
			this->listBoxHistory->Size = System::Drawing::Size(279, 134);
			this->listBoxHistory->TabIndex = 2;
			// 
			// buttonConnect
			// 
			this->buttonConnect->Location = System::Drawing::Point(211, 11);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(75, 23);
			this->buttonConnect->TabIndex = 3;
			this->buttonConnect->Text = L"Connect";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &MyForm::buttonConnect_Click);
			// 
			// textBoxUsername
			// 
			this->textBoxUsername->Location = System::Drawing::Point(70, 13);
			this->textBoxUsername->Name = L"textBoxUsername";
			this->textBoxUsername->Size = System::Drawing::Size(135, 20);
			this->textBoxUsername->TabIndex = 4;
			this->textBoxUsername->Text = L"User1234";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Username:";
			// 
			// groupBoxConnect
			// 
			this->groupBoxConnect->Controls->Add(this->label1);
			this->groupBoxConnect->Controls->Add(this->buttonConnect);
			this->groupBoxConnect->Controls->Add(this->textBoxUsername);
			this->groupBoxConnect->Location = System::Drawing::Point(12, 12);
			this->groupBoxConnect->Name = L"groupBoxConnect";
			this->groupBoxConnect->Size = System::Drawing::Size(292, 40);
			this->groupBoxConnect->TabIndex = 6;
			this->groupBoxConnect->TabStop = false;
			this->groupBoxConnect->Text = L"Connect";
			// 
			// groupBoxMessenger
			// 
			this->groupBoxMessenger->Controls->Add(this->label2);
			this->groupBoxMessenger->Controls->Add(this->comboBox1);
			this->groupBoxMessenger->Controls->Add(this->textBoxMessage);
			this->groupBoxMessenger->Controls->Add(this->buttonSend);
			this->groupBoxMessenger->Controls->Add(this->listBoxHistory);
			this->groupBoxMessenger->Enabled = false;
			this->groupBoxMessenger->Location = System::Drawing::Point(13, 59);
			this->groupBoxMessenger->Name = L"groupBoxMessenger";
			this->groupBoxMessenger->Size = System::Drawing::Size(291, 240);
			this->groupBoxMessenger->TabIndex = 7;
			this->groupBoxMessenger->TabStop = false;
			this->groupBoxMessenger->Text = L"Messenger";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"All" });
			this->comboBox1->Location = System::Drawing::Point(67, 20);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(218, 21);
			this->comboBox1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Recipient:";
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(318, 313);
			this->Controls->Add(this->groupBoxMessenger);
			this->Controls->Add(this->groupBoxConnect);
			this->Name = L"MyForm";
			this->Text = L"Client";
			this->groupBoxConnect->ResumeLayout(false);
			this->groupBoxConnect->PerformLayout();
			this->groupBoxMessenger->ResumeLayout(false);
			this->groupBoxMessenger->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		void ConnectToServer() {
			client = gcnew TcpClient("127.0.0.1", 8080);
			NetworkStream^ stream = client->GetStream();
			reader = gcnew StreamReader(stream);
			writer = gcnew StreamWriter(stream);
			writer->AutoFlush = true;

			Task::Run(gcnew Action(this, &MyForm::ReceiveMessages));
		}

		void SendButton_Click(Object^ sender, EventArgs^ e) {
			String^ message = textBoxMessage->Text;
			if (!String::IsNullOrEmpty(message)) {
				message = "[" + textBoxUsername->Text + "]: " + message;
				if (comboBox1->SelectedItem != "All") {
					AddMessageToList(message);
					message = "w " + comboBox1->SelectedItem + " " + message;
					writer->WriteLine(message);
					textBoxMessage->Clear();
					return;
				}
				writer->WriteLine(message);
				AddMessageToList(message);
				textBoxMessage->Clear();
			}
		}

		void ReceiveMessages() {
			while (true) {
				String^ message = reader->ReadLine();
				if (message != nullptr) {
					if (message[0] == 'c') {
						comboBox1->Items->Add(message->Split(' ')[1]);
						AddMessageToList(message->Split(' ')[1] + " connected.");
						message = "r " + message->Split(' ')[1] + " " + textBoxUsername->Text;
						writer->WriteLine(message);
					}
					else if (message[0] == 'r' ) {
						if(message->Split(' ')[1] == textBoxUsername->Text)
							comboBox1->Items->Add(message->Split(' ')[2]);
					}
					else if (message[0] == 'w') {
						if (message->Split(' ')[1] == textBoxUsername->Text) {
							this->Invoke(gcnew Action<String^>(this, &MyForm::AddMessageToList), message->Remove(0, 3 + textBoxUsername->Text->Length));
						}
					}
					else this->Invoke(gcnew Action<String^>(this, &MyForm::AddMessageToList), message);
				}
			}
		}

		void AddMessageToList(String^ message) {
			listBoxHistory->Items->Add(message);
		}

	private: System::Void buttonConnect_Click(System::Object^ sender, System::EventArgs^ e) {
		ConnectToServer();
		groupBoxConnect->Enabled = false;
		groupBoxMessenger->Enabled = true;

		String^ message = "c " + textBoxUsername->Text;
		writer->WriteLine(message);
	}
	};
}
