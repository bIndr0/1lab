#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

using namespace std;

class Patient{
private:
    string name; 
    string pain;
    int time;

    Patient *next;
    Patient *prev;

public:
    Patient();
    Patient(string n, string p, int t);

    ~Patient();

    string GetName();
    string GetPain();
    int GetTime();

    Patient *GetNext();
    Patient *GetPrev();

    void SetName(string n);
    void SetPain(string p);
    void SetTime(int t);

    void SetNext(Patient *n);
    void SetPrev(Patient *p);
    
    friend ostream& operator << (ostream &out, const Patient &exc);
    friend istream& operator >> (istream &in, Patient &exc);

};

#endif // PATIENT_H
