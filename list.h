#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "patient.h"

using namespace std;

class List
{
private:
    int size;
    Patient *head;

public:
    List();
    ~List();

    void Print();
    void Push();
    void Del(int index);
    int Size();
    void AddNew();
    void Swap(Patient *left, Patient *rigth);

    Patient *Find(int index);
    Patient *GetHead();
    void SetHead(Patient *h);
};

#endif // LIST_H
