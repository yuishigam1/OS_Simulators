#pragma once
#include "sjf.h"

namespace OSSimulators {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Index
	/// </summary>
	public ref class Index : public System::Windows::Forms::Form
	{
	public:
		Index(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Index()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(9, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(665, 66);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Shortest Job First (SJF) scheduling algorithm ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Index::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(9, 112);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(665, 64);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Dining philosophers’ problem with semaphore";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(9, 213);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(665, 64);
			this->button3->TabIndex = 2;
			this->button3->Text = L"C-Look disk scheduling algorithm ";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(9, 312);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(665, 64);
			this->button4->TabIndex = 3;
			this->button4->Text = L"First-in first-out (FIFO) page replacement algorithm";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// Index
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(686, 408);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Index";
			this->Text = L"Index";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		sjf^ sjf_form = gcnew sjf();

		sjf_form->Show();
	}
	};
}
