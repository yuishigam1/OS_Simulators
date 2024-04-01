#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <map>
#include <string>
#include <mutex>
#include <msclr/marshal_cppstd.h> // Required for string conversion

namespace OSSimulators {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Threading;
    using namespace System::Drawing; // Required for color manipulation
    using namespace std::chrono;

    public ref class dppVisual : public Form {
    public:
        dppVisual(int* arrivalTimes, int size) {
            InitializeComponent();
            A = arrivalTimes;
            N = size;
            ChopSticks = new int[N];
            chopsticksMutex = gcnew Mutex();
            finishedEatingCount = 0; // Initialize the counter
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
        int* ChopSticks;
        int finishedEatingCount; // Counter to keep track of finished philosophers
        RichTextBox^ richTextBox1; // Use RichTextBox for text formatting
        System::ComponentModel::Container^ components;
        Mutex^ chopsticksMutex;

        void InitializeComponent(void) {
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->SuspendLayout();
            // 
            // richTextBox1
            // 
            this->richTextBox1->BackColor = System::Drawing::SystemColors::InactiveBorder;
            this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->richTextBox1->Location = System::Drawing::Point(0, 0);
            this->richTextBox1->Margin = System::Windows::Forms::Padding(4);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(709, 482);
            this->richTextBox1->TabIndex = 0;
            this->richTextBox1->Text = L"";
            // 
            // dppVisual
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(710, 479);
            this->Controls->Add(this->richTextBox1);
            this->Margin = System::Windows::Forms::Padding(4);
            this->Name = L"dppVisual";
            this->Text = L"dppVisual";
            this->ResumeLayout(false);

        }

        void StartSimulation() {
            int i = 0;
            while (i < N)
            {
                ChopSticks[i] = 1;
                i++;
            }
            for (int i = 0; i < N; ++i) {
                int arrivalTime = A[i];
                String^ philosopherName = "p" + (i + 1);
                UpdateRichTextBox("Philosopher " + philosopherName + " has arrived.\r\n", Color::Orange); // Default color
                // Start a new thread for each philosopher
                Thread^ philosopherThread = gcnew Thread(gcnew ParameterizedThreadStart(this, &dppVisual::SimulatePhilosopherActivity));
                philosopherThread->Start(philosopherName + " " + System::Convert::ToString(arrivalTime));
            }
        }

        void SimulatePhilosopherActivity(Object^ data) {
            int maxIterations = 1; // Number of times each philosopher will alternate between thinking and eating
            String^ param = safe_cast<String^>(data);
            array<String^>^ params = param->Split(' ');
            String^ philosopherName = params[0];
            int arrivalTime = System::Convert::ToInt32(params[1]);
            int philosopherNO = System::Convert::ToInt32(philosopherName[1]);

            for (int i = 0; i < maxIterations; ++i) {
                System::Threading::Thread::Sleep(arrivalTime * 1000);

                // Lock the chopsticks
                chopsticksMutex->WaitOne();

                // Check if both chopsticks are available
                while (ChopSticks[philosopherNO] == 0 || ChopSticks[(philosopherNO + 1) % N] == 0) {
                    // If not available, release the lock and wait
                    chopsticksMutex->ReleaseMutex();
                    System::Threading::Thread::Sleep(1000);
                    chopsticksMutex->WaitOne();
                }

                // If both chopsticks are available, philosopher starts eating
                ChopSticks[philosopherNO] = 0;
                ChopSticks[(philosopherNO + 1) % N] = 0;
                UpdateRichTextBox("Philosopher " + philosopherName + " is eating.\r\n", Color::Black); // Change text color

                // Release the lock
                chopsticksMutex->ReleaseMutex();

                // Philosopher eats for some time
                System::Threading::Thread::Sleep(1000);

                // Lock the chopsticks again
                chopsticksMutex->WaitOne();

                // Philosopher puts back the chopsticks
                ChopSticks[philosopherNO] = 1;
                ChopSticks[(philosopherNO + 1) % N] = 1;
                UpdateRichTextBox("Philosopher " + philosopherName + " has finished eating.\r\n", Color::Green); // Change text color

                // Release the lock
                chopsticksMutex->ReleaseMutex();

                // Philosopher thinks for some time
                UpdateRichTextBox("Philosopher " + philosopherName + " is thinking.\r\n", Color::Black); // Change text color
                System::Threading::Thread::Sleep(1000);
            }

            // Increment the finished eating count
            Interlocked::Increment(finishedEatingCount);

            // Check if all philosophers have finished eating
            if (finishedEatingCount == N) {
                UpdateRichTextBox("All philosophers have finished eating. Simulation complete.\r\n", Color::Blue); // Change text color
            }
        }

        void UpdateRichTextBox(String^ newText, Color textColor) {
            // Set the text color before appending the text
            this->richTextBox1->SelectionColor = textColor;
            this->richTextBox1->AppendText(newText);
            // Reset the text color to default
            this->richTextBox1->SelectionColor = this->richTextBox1->ForeColor;
        }
        // Inside the dppVisual class definition
        private: System::Void dppVisual_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
            // Close all open forms
            for each (Form ^ form in Application::OpenForms) {
                form->Close();
            }
        }
};
}
