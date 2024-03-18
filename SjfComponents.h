#pragma once
#include<vector>
#include<iostream>
#pragma once

public ref class SjfComponents
{
public:
    SjfComponents() {
    }

    ~SjfComponents() {

    }
    int size;
    array<System::String^>^ processName;
    int* arrivalTime;
    int* burstTime;
    int* completionTime;
    int* turnAroundTime;
    int* waitingTime;


    SjfComponents(int size) {
        this->size = size;
        this->processName = gcnew array<System::String^>(size);
        this->arrivalTime = new int[size];
        this->burstTime = new int[size];
        this->completionTime = new int[size];
        this->turnAroundTime = new int[size];
        this->waitingTime = new int[size];
    }

    void sort(void){
        for (int i = 0; i < this->size; i++) {
            for (int j = i + 1; j < this->size; j++) {
                if (this->completionTime[i] > this->completionTime[j]) {

                    //Create a temporary component object for swap
                    SjfComponents^ temp = gcnew SjfComponents(1);

                    //Swap the process
                    temp->processName[0] = this->processName[i];
                    temp->arrivalTime[0] = this->arrivalTime[i];
                    temp->burstTime[0] = this->burstTime[i];
                    temp->completionTime[0] = this->completionTime[i];
                    temp->turnAroundTime[0] = this->turnAroundTime[i];
                    temp->waitingTime[0] = this->waitingTime[i];

                    this->processName[i] = this->processName[j];
                    this->arrivalTime[i] = this->arrivalTime[j];
                    this->burstTime[i] = this->burstTime[j];
                    this->completionTime[i] = this->completionTime[j];
                    this->turnAroundTime[i] = this->turnAroundTime[j];
                    this->waitingTime[i] = this->waitingTime[j];

                    this->processName[j] = temp->processName[0];
                    this->arrivalTime[j] = temp->arrivalTime[0];
                    this->burstTime[j] = temp->burstTime[0];
                    this->completionTime[j] = temp->completionTime[0];
                    this->turnAroundTime[j] = temp->turnAroundTime[0];
                    this->waitingTime[j] = temp->waitingTime[0];
                }
            }
        }
    }
};