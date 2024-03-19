#pragma once
#include "sjf.h"
#include "dpp.h"
#include "My.h"
#include "CLook.h"

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
	private: System::Windows::Forms::Button^ sjf_btn;
	private: System::Windows::Forms::Button^ dp_btn;
	protected:


	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	sjf^ sjf_form = gcnew sjf();
	dpp^ dpp_form = gcnew dpp();
	My^ fifo_form = gcnew My();
	CLook^ cLook_form = gcnew CLook();


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Index::typeid));
			this->sjf_btn = (gcnew System::Windows::Forms::Button());
			this->dp_btn = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// sjf_btn
			// 
			this->sjf_btn->BackColor = System::Drawing::Color::Transparent;
			this->sjf_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->sjf_btn->FlatAppearance->BorderColor = System::Drawing::Color::DarkSeaGreen;
			this->sjf_btn->FlatAppearance->BorderSize = 2;
			this->sjf_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sjf_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sjf_btn->ForeColor = System::Drawing::Color::Gold;
			this->sjf_btn->Location = System::Drawing::Point(9, 46);
			this->sjf_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->sjf_btn->Name = L"sjf_btn";
			this->sjf_btn->Size = System::Drawing::Size(665, 66);
			this->sjf_btn->TabIndex = 0;
			this->sjf_btn->Text = L"Shortest Job First (SJF) scheduling algorithm ";
			this->sjf_btn->UseVisualStyleBackColor = false;
			this->sjf_btn->Click += gcnew System::EventHandler(this, &Index::button1_Click);
			// 
			// dp_btn
			// 
			this->dp_btn->BackColor = System::Drawing::Color::Transparent;
			this->dp_btn->FlatAppearance->BorderColor = System::Drawing::Color::DarkSeaGreen;
			this->dp_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dp_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dp_btn->ForeColor = System::Drawing::Color::Gold;
			this->dp_btn->Location = System::Drawing::Point(9, 143);
			this->dp_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dp_btn->Name = L"dp_btn";
			this->dp_btn->Size = System::Drawing::Size(665, 64);
			this->dp_btn->TabIndex = 1;
			this->dp_btn->Text = L"Dining philosophers’ problem with semaphore";
			this->dp_btn->UseVisualStyleBackColor = false;
			this->dp_btn->Click += gcnew System::EventHandler(this, &Index::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::DarkSeaGreen;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Gold;
			this->button3->Location = System::Drawing::Point(9, 236);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(665, 64);
			this->button3->TabIndex = 2;
			this->button3->Text = L"C-Look disk scheduling algorithm ";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Index::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Transparent;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::DarkSeaGreen;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Gold;
			this->button4->Location = System::Drawing::Point(9, 320);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(665, 64);
			this->button4->TabIndex = 3;
			this->button4->Text = L"First-in first-out (FIFO) page replacement algorithm";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Index::button4_Click);
			// 
			// Index
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(685, 409);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->dp_btn);
			this->Controls->Add(this->sjf_btn);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Index";
			this->Text = L"OS Simulator";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		if (!sjf_form->Visible) {

			sjf_form->Show();
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!dpp_form->Visible)
		{
			dpp_form->Show();
			this->Hide();
		}
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!fifo_form->Visible)
		{
			fifo_form->Show();
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!cLook_form->Visible)
		{
			cLook_form->Show();
		}
	}
};
}
