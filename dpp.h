#pragma once
#include"dppVisual.h"
namespace OSSimulators {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// <summary>
	/// Summary for dpp
	/// </summary>
	public ref class dpp : public System::Windows::Forms::Form
	{
	Boolean buttonClicked = false;
	public:

		dpp(void)
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
		~dpp()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ Submit;
	private: System::Windows::Forms::TextBox^ NoOfPhilo;
	private: System::Windows::Forms::Label^ l1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Philoshoper;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ AT;


	protected:

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
			this->Submit = (gcnew System::Windows::Forms::Button());
			this->NoOfPhilo = (gcnew System::Windows::Forms::TextBox());
			this->l1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Philoshoper = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// Submit
			// 
			this->Submit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Submit->Location = System::Drawing::Point(140, 64);
			this->Submit->Name = L"Submit";
			this->Submit->Size = System::Drawing::Size(100, 36);
			this->Submit->TabIndex = 0;
			this->Submit->Text = L"Submit";
			this->Submit->UseVisualStyleBackColor = true;
			this->Submit->Click += gcnew System::EventHandler(this, &dpp::Submit_Click);
			// 
			// NoOfPhilo
			// 
			this->NoOfPhilo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NoOfPhilo->Location = System::Drawing::Point(17, 67);
			this->NoOfPhilo->Name = L"NoOfPhilo";
			this->NoOfPhilo->Size = System::Drawing::Size(100, 30);
			this->NoOfPhilo->TabIndex = 1;
			// 
			// l1
			// 
			this->l1->AutoSize = true;
			this->l1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->l1->Location = System::Drawing::Point(12, 22);
			this->l1->Name = L"l1";
			this->l1->Size = System::Drawing::Size(228, 25);
			this->l1->TabIndex = 2;
			this->l1->Text = L"Enter no of philoshopers:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::Disable;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Philoshoper,
					this->AT
			});
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->dataGridView1->Location = System::Drawing::Point(12, 181);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(356, 295);
			this->dataGridView1->TabIndex = 3;
			// 
			// Philoshoper
			// 
			this->Philoshoper->Frozen = true;
			this->Philoshoper->HeaderText = L"Philoshoper";
			this->Philoshoper->MinimumWidth = 6;
			this->Philoshoper->Name = L"Philoshoper";
			this->Philoshoper->Width = 125;
			// 
			// AT
			// 
			this->AT->Frozen = true;
			this->AT->HeaderText = L"Arrival Time";
			this->AT->MinimumWidth = 6;
			this->AT->Name = L"AT";
			this->AT->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->AT->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->AT->Width = 115;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(17, 121);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 35);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Set AT";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &dpp::button1_Click);
			// 
			// dpp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(380, 505);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->l1);
			this->Controls->Add(this->NoOfPhilo);
			this->Controls->Add(this->Submit);
			this->Name = L"dpp";
			this->Text = L"dpp";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Submit_Click(System::Object^ sender, System::EventArgs^ e) {
		int N = System::Convert::ToInt32(NoOfPhilo->Text);
		int i = 0;
		int* array = new int[N];
		if (buttonClicked==true)
		{
			while (i < N)
			{
				if (String::IsNullOrEmpty(System::Convert::ToString(dataGridView1->Rows[i]->Cells[1]->Value)))
				{
					array[i] = i;
				}
				else
				{
					array[i] = System::Convert::ToInt32(dataGridView1->Rows[i]->Cells[1]->Value);
				}
				i++;
			}
		}
		else
		{
			while (i < N)
			{
				array[i] = i;
				i++;
			}
		}
		while (i < N)
		{
			array[i] = i;
			i++;
		}
		dppVisual^ dpp_form = gcnew dppVisual(array,N);
		dpp_form->Show();
		this->Hide();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		buttonClicked = true;
		int N = System::Convert::ToInt32(NoOfPhilo->Text);
		int i = 0;
		while (i < N)
		{
			dataGridView1->Rows->Add();
			i++;
		}
		i = 0;
		while (i < N)
		{
			dataGridView1->Rows[i]->Cells[0]->Value = "P" + System::Convert::ToString(i);
			i++;
		}
	}
};
}
