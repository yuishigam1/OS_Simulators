#pragma once
#include<iostream>
#include<algorithm>
namespace OSSimulators {
	
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for dppVisual
	/// </summary>
	public ref class dppVisual : public System::Windows::Forms::Form
	{
	public:
		int* A,N;
		dppVisual(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		dppVisual(int *array,int size)
		{
			InitializeComponent();
			A = array;
			N = size;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~dppVisual()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:

	protected:

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(0, 0);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(399, 481);
			this->textBox1->TabIndex = 0;
			// 
			// dppVisual
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(400, 479);
			this->Controls->Add(this->textBox1);
			this->Name = L"dppVisual";
			this->Text = L"dppVisual";
			this->Load += gcnew System::EventHandler(this, &dppVisual::dppVisual_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dppVisual_Load(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = System::Convert::ToString(N);
		int i = 0;
		std::sort();
	}
	};
}
