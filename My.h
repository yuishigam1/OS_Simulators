#pragma once

namespace OSSimulators {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for My
	/// </summary>
	public ref class My : public System::Windows::Forms::Form
	{
	public:
		My(void)
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
		~My()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxPageSequence;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxCapacity;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buttonCalculate;
	private: System::Windows::Forms::Label^ labelOutput;

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
			this->textBoxPageSequence = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxCapacity = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonCalculate = (gcnew System::Windows::Forms::Button());
			this->labelOutput = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxPageSequence
			// 
			this->textBoxPageSequence->BackColor = System::Drawing::Color::Black;
			this->textBoxPageSequence->ForeColor = System::Drawing::Color::Gold;
			this->textBoxPageSequence->Location = System::Drawing::Point(143, 15);
			this->textBoxPageSequence->Margin = System::Windows::Forms::Padding(4);
			this->textBoxPageSequence->Name = L"textBoxPageSequence";
			this->textBoxPageSequence->Size = System::Drawing::Size(132, 22);
			this->textBoxPageSequence->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 19);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Page Sequence";
			// 
			// textBoxCapacity
			// 
			this->textBoxCapacity->BackColor = System::Drawing::Color::Black;
			this->textBoxCapacity->ForeColor = System::Drawing::Color::Gold;
			this->textBoxCapacity->Location = System::Drawing::Point(143, 63);
			this->textBoxCapacity->Margin = System::Windows::Forms::Padding(4);
			this->textBoxCapacity->Name = L"textBoxCapacity";
			this->textBoxCapacity->Size = System::Drawing::Size(132, 22);
			this->textBoxCapacity->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 67);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Memory Capacity";
			// 
			// buttonCalculate
			// 
			this->buttonCalculate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonCalculate->Location = System::Drawing::Point(13, 107);
			this->buttonCalculate->Margin = System::Windows::Forms::Padding(4);
			this->buttonCalculate->Name = L"buttonCalculate";
			this->buttonCalculate->Size = System::Drawing::Size(262, 28);
			this->buttonCalculate->TabIndex = 4;
			this->buttonCalculate->Text = L"Calculate";
			this->buttonCalculate->UseVisualStyleBackColor = true;
			this->buttonCalculate->Click += gcnew System::EventHandler(this, &My::buttonCalculate_Click);
			// 
			// labelOutput
			// 
			this->labelOutput->AutoSize = true;
			this->labelOutput->Location = System::Drawing::Point(59, 181);
			this->labelOutput->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelOutput->Name = L"labelOutput";
			this->labelOutput->Size = System::Drawing::Size(0, 16);
			this->labelOutput->TabIndex = 5;
			// 
			// My
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(298, 157);
			this->Controls->Add(this->labelOutput);
			this->Controls->Add(this->buttonCalculate);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxCapacity);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxPageSequence);
			this->ForeColor = System::Drawing::Color::Gold;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"My";
			this->Text = L"MyForm1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
     private:
         void fifoPageReplacement(List<int>^ pages, int capacity) {
             cli::array<bool>^ visited = gcnew cli::array<bool>(100);
             System::Collections::Generic::Queue<int>^ pageQueue = gcnew System::Collections::Generic::Queue<int>();
             int pageFaults = 0;

             for each (int page in pages) {
                 if (!visited[page]) {
                     pageFaults++;
                     if (pageQueue->Count == capacity) {
                         int oldestPage = pageQueue->Dequeue();
                         visited[oldestPage] = false;
                     }
                     pageQueue->Enqueue(page);
                     visited[page] = true;
                 }
             }
			 MessageBox::Show("Total Page Faults: " + pageFaults, "", MessageBoxButtons::OK);
         }

         System::Void buttonCalculate_Click(System::Object^ sender, System::EventArgs^ e) {
             String^ pageSequence = textBoxPageSequence->Text;
             List<int>^ pages = gcnew List<int>();
             for each (String ^ pageStr in pageSequence->Split(' ')) {
                 int page;
                 if (Int32::TryParse(pageStr, page))
                     pages->Add(page);
             }

             int capacity;
             if (Int32::TryParse(textBoxCapacity->Text, capacity)) {
                 fifoPageReplacement(pages, capacity);
             }
             else {
                 labelOutput->Text = "Invalid capacity input.";
             }
         }


};
}