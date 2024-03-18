#pragma once
#include <iostream>
#include "SjfComponents.h"
#include <vector>
#include "GanttChart.h"
#include <msclr/marshal.h>

namespace OSSimulators {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for sjf
	/// </summary>
	public ref class sjf : public System::Windows::Forms::Form
	{
	public:
		sjf(void)
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
		~sjf()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
		   GanttChart^ gantt_chart_window;



	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProcessName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ArrivalTime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ BurstTime;



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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ProcessName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ArrivalTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->BurstTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle11->NullValue = nullptr;
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle11;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle12->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle12->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle12->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle12->Format = L"N2";
			dataGridViewCellStyle12->NullValue = L"0";
			dataGridViewCellStyle12->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle12->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle12->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle12;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->ProcessName,
					this->ArrivalTime, this->BurstTime
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 54);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(651, 244);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->TabStop = false;
			// 
			// ProcessName
			// 
			this->ProcessName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->ProcessName->HeaderText = L"Process Name";
			this->ProcessName->MinimumWidth = 6;
			this->ProcessName->Name = L"ProcessName";
			this->ProcessName->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// ArrivalTime
			// 
			this->ArrivalTime->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->ArrivalTime->HeaderText = L"Arrival Time";
			this->ArrivalTime->MinimumWidth = 6;
			this->ArrivalTime->Name = L"ArrivalTime";
			// 
			// BurstTime
			// 
			this->BurstTime->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->BurstTime->HeaderText = L"Burst Time";
			this->BurstTime->MinimumWidth = 6;
			this->BurstTime->Name = L"BurstTime";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Enter Parameters";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 317);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(651, 31);
			this->button1->TabIndex = 2;
			this->button1->Text = L"GO";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &sjf::button1_Click);
			// 
			// sjf
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(675, 360);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"sjf";
			this->Text = L"Shortest Job First (SJF)";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

private: System::Void dataGridView1_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e) {
	// Get the index of the newly added row
	int rowIndex = e->RowIndex;

	// Set default value for the first cell of the new row
	dataGridView1->Rows[rowIndex]->Cells[0]->Value = "Default Value";
}


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


	if (dataGridView1->RowCount > 1) {
		//create object of sjfComponent class
		SjfComponents^ sjf_components = gcnew SjfComponents(dataGridView1->RowCount - 1);
		
		sjf_components->processName[0] = Convert::ToString(dataGridView1->Rows[0]->Cells[0]->Value);
		sjf_components->arrivalTime[0] = Convert::ToInt32(dataGridView1->Rows[0]->Cells[1]->Value);
		sjf_components->burstTime[0] = Convert::ToInt32(dataGridView1->Rows[0]->Cells[2]->Value);
		int pWithMinArrivalTime = 0;
		int final_state = 0;
		std::vector<int> p_queue;

		for (int i = 1; i < dataGridView1->RowCount - 1; i++) {

			//Getting Process Name
			sjf_components->processName[i] = Convert::ToString(dataGridView1->Rows[i]->Cells[0]->Value);

			// Getting Arrival Time
			sjf_components->arrivalTime[i] = Convert::ToInt32(dataGridView1->Rows[i]->Cells[1]->Value);

			// Getting Burst Time
			sjf_components->burstTime[i] = Convert::ToInt32(dataGridView1->Rows[i]->Cells[2]->Value);

			if (sjf_components->arrivalTime[pWithMinArrivalTime] > sjf_components->arrivalTime[i]) {
				pWithMinArrivalTime = i;
			}
		}

		p_queue.push_back(pWithMinArrivalTime);

		while (!p_queue.empty())
		{
			int pWithMinBurstTime = p_queue.at(0);
			if (p_queue.size() > 1) {
				int delEleIndex = 0;
				for (int i = 1; i < p_queue.size(); i++) {
					if (sjf_components->burstTime[pWithMinBurstTime] > sjf_components->burstTime[p_queue.at(i)]) {
						pWithMinBurstTime = p_queue.at(i);
						delEleIndex = i;
					}
				}
				sjf_components->completionTime[pWithMinBurstTime] = final_state + sjf_components->burstTime[pWithMinBurstTime];
				p_queue.erase(p_queue.begin() + delEleIndex);
			}
			else
			{
				sjf_components->completionTime[pWithMinBurstTime] = final_state + sjf_components->burstTime[pWithMinBurstTime];
				p_queue.clear();
			}
			for (int i = 0; i < sjf_components->size; i++) {
				if (sjf_components->arrivalTime[i] <= sjf_components->completionTime[pWithMinBurstTime] && sjf_components->arrivalTime[i] > final_state) {
					p_queue.push_back(i);
				}
			}
			final_state = sjf_components->completionTime[pWithMinBurstTime];
		}

		if (dataGridView1->ColumnCount == 3) {

			dataGridView1->Columns->Add("ComplitionTime", "Complition Time");
			dataGridView1->Columns->Add("TurnAroundTime", "Turn Around Time");
			dataGridView1->Columns->Add("WaitingTime", "Waiting Time");

			for (int i = 0; i < sjf_components->size; i++) {
				sjf_components->turnAroundTime[i] = sjf_components->completionTime[i] - sjf_components->arrivalTime[i];
				sjf_components->waitingTime[i] = sjf_components->turnAroundTime[i] - sjf_components->burstTime[i];
				dataGridView1->Rows[i]->Cells[3]->Value = sjf_components->completionTime[i];
				dataGridView1->Rows[i]->Cells[4]->Value = sjf_components->turnAroundTime[i];
				dataGridView1->Rows[i]->Cells[5]->Value = sjf_components->waitingTime[i];
			}
		}

		
		gantt_chart_window = gcnew GanttChart(sjf_components);
		gantt_chart_window->Show();

	}
	else {
		std::cout << "Enter Data First !!" << std::endl;
	}



	




}
};
}
