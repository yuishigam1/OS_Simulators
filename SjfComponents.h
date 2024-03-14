#pragma once
#include<vector>

class SjfComponents
{
public:
    int size;
    int* arrivalTime;
    int* burstTime;
    int* completionTime;
    int* turnAroundTime;
    int* waitingTime;

    SjfComponents(int size = 0) {
        this->size = size;
        this->arrivalTime = new int[size];
        this->burstTime = new int[size];
        this->completionTime = new int[size];
        this->turnAroundTime = new int[size];
        this->waitingTime = new int[size];
    }
};