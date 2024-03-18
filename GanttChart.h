#include "SjfComponents.h"
#include <iostream>

#pragma once

namespace OSSimulators {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GanttChart
	/// </summary>
	public ref class GanttChart : public System::Windows::Forms::Form
	{
	public:
		SjfComponents^ sjf_components;
		GanttChart(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		GanttChart(SjfComponents^ obj)
		{
			this->sjf_components = obj;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GanttChart()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:
		virtual void OnPaint(PaintEventArgs^ e) override
		{
			Graphics^ g = e->Graphics;
			Pen^ pen = gcnew Pen(Color::Black);

			sjf_components->sort();
			int startY = 50; // Initial Y position of the tasks
			int height = 50; // Height of each task
			int preX = 50;
			// Draw tasks
			g->DrawString(Convert::ToString(sjf_components->arrivalTime[0]), gcnew Drawing::Font("Arial", 10), Brushes::Black, 45, startY + height + 10);
			for(int i = 0; i < sjf_components->size; i++)
			{
				String^ name = sjf_components->processName[i];
				int startX = preX;
				int endX = startX + sjf_components->burstTime[i] * 10;
				int width = endX - startX;


				Drawing::Rectangle rect(startX, startY, width, height);
				g->DrawRectangle(pen, rect);
				g->DrawLine(pen, startX, startY + height, startX, startY + height + 10); // Start line
				g->DrawLine(pen, endX, startY + height, endX, startY + height + 10); // End line

				// Draw task name
				g->DrawString(name, gcnew Drawing::Font("Arial", 10), Brushes::Black, startX + 5, startY + 5);
				if (Convert::ToString(sjf_components->completionTime[i])->Length == 1) {

					g->DrawString(Convert::ToString(sjf_components->completionTime[i]), gcnew Drawing::Font("Arial", 10), Brushes::Black, endX - 5, startY + height + 10);
				}
				else
				{
					g->DrawString(Convert::ToString(sjf_components->completionTime[i]), gcnew Drawing::Font("Arial", 10), Brushes::Black, endX - 10, startY + height + 10);
				}

				preX = endX;
			}
		}
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
			this->SuspendLayout();
			// 
			// GanttChart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(643, 334);
			this->Name = L"GanttChart";
			this->Text = L"GanttChart";
			this->Load += gcnew System::EventHandler(this, &GanttChart::GanttChart_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void GanttChart_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Invalidate();
	}
	};

	
}
