#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <map>
#include <string>
#include <msclr/marshal_cppstd.h> // Required for string conversion

namespace OSSimulators {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Threading;
    using namespace std::chrono;

    public ref class dppVisual : public Form {
    public:
        dppVisual(int* arrivalTimes, int size) {
            InitializeComponent();
            A = arrivalTimes;
            N = size;

            StartSimulation();
        }

    protected:
        ~dppVisual() {
            if (components) {
                delete components;
            }
        }

    private:
        int* A;
        int N;

        TextBox^ textBox1;
        System::ComponentModel::Container^ components; // Add this line

        void InitializeComponent(void) {
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->BackColor = System::Drawing::SystemColors::InactiveBorder;
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox1->Location = System::Drawing::Point(0, 0);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(300, 392);
            this->textBox1->TabIndex = 0;
            // 
            // dppVisual
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(300, 389);
            this->Controls->Add(this->textBox1);
            this->Name = L"dppVisual";
            this->Text = L"dppVisual";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void StartSimulation() {
            for (int i = 0; i < N; ++i) {
                int arrivalTime = A[i];
                String^ philosopherName = "p" + (i + 1);
                UpdateTextBox("Philosopher " + philosopherName + " has arrived.\r\n");

                // Start a new thread for each philosopher
                Thread^ philosopherThread = gcnew Thread(gcnew ParameterizedThreadStart(this, &dppVisual::SimulatePhilosopherActivity));
                philosopherThread->Start(philosopherName+"  "+ System::Convert::ToString(arrivalTime));
            }
        }

        void SimulatePhilosopherActivity(Object^ data) {
            array<Object^>^ params = safe_cast<array<Object^>^>(data);
            String^ philosopherName = safe_cast<String^>(params[0]);
            int arrivalTime = safe_cast<int>(params[1]);

            System::Threading::Thread::Sleep(arrivalTime * 1000);

            UpdateTextBox("Philosopher " + philosopherName + " is eating.\r\n");
            System::Threading::Thread::Sleep(1000); // Simulate eating time

            UpdateTextBox("Philosopher " + philosopherName + " has finished eating.\r\n");
        }

        void UpdateTextBox(String^ newText) {
                this->textBox1->AppendText(newText);
        }
    };
}
