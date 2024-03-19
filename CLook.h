#pragma once
#include "CLookAlgo.h"
#include <vector>

namespace OSSimulators {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CLook
	/// </summary>
	public ref class CLook : public System::Windows::Forms::Form
	{
	public:
		CLook(void)
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
		~CLook()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox3;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Number Of Tracks: ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(174, 26);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 113);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(129, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Enter Target Tracks:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(174, 70);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(130, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Enter Starting Track: ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 161);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Direction:";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"LEFT", L"RIGHT" });
			this->comboBox1->Location = System::Drawing::Point(15, 189);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(126, 24);
			this->comboBox1->TabIndex = 7;
			this->comboBox1->Tag = L"";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(12, 229);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(262, 35);
			this->button1->TabIndex = 8;
			this->button1->Text = L"GET";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &CLook::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(174, 113);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox3->Size = System::Drawing::Size(100, 100);
			this->textBox3->TabIndex = 9;
			// 
			// CLook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(287, 287);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"CLook";
			this->Text = L"CLook";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		int numOfTracks = Convert::ToInt32(textBox1->Text);
		int startingTrack = Convert::ToInt32(textBox2->Text);
		bool direction;
		if (comboBox1->SelectedIndex == 0) {
			direction = false;
		}
		else {
			direction = true;
		}

		std::vector<int> target_tracks;
		for (int i = 0; i < textBox3->Lines->Length; i++) {
			target_tracks.push_back(Convert::ToInt32(textBox3->Lines[i]));
		}

		
		CLookDiskSchedulingAlgo* cLook = new CLookDiskSchedulingAlgo(target_tracks, numOfTracks, startingTrack);


		MessageBox::Show("The Number Of Converd Tracks Is: " + cLook->getCoveredTracks(direction), "", MessageBoxButtons::OK);
	}
};
}
