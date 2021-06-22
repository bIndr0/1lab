#include "patient.h"
#include <iostream>
#include <string>

Patient::Patient(){}
Patient::Patient(string n, string p, int t)
{
    name = n;
    pain = p;
    time = t;
}

Patient::~Patient(){}

string Patient::GetName()
{
    return Patient::name;
}

string Patient::GetPain()
{
    return Patient::pain;
}

int Patient::GetTime()
{
    return time;
}

Patient *Patient::GetNext()
{
    return next;
}

Patient *Patient::GetPrev()
{
    return prev;
}

void Patient::SetName(string n)
{
    if (n != " "){
       name = n;
    }
    else{
        cout << "error" << endl;
    }

}

void Patient::SetPain(string p)
{
    if (p != " "){
        pain = p;
    }
    else{
        cout << "error" << endl;
    }
}


void Patient::SetTime(int t)
{
    if (t >= 0){
        time = t;
    }
    else{
        cout << "error" << endl;
    }
}


void Patient::SetNext(Patient *n)
{
    next = n;
}

void Patient::SetPrev(Patient *p)
{
    prev = p;
}

ostream& operator <<(ostream &out, const Patient &exc)
{
    out << "Имя пациента: " << exc.name << endl;
    out << "Заболевание/Диагноз: " << exc.pain << endl;
    out << "Время на лечене: " << exc.time << endl;
    return out;
}
istream& operator >> (istream &in, Patient &exc)
{
    string n;
    cout << "Имя пациента: ";
    in >> exc.name;

    string p;
    cout << "Заболевание/Диагноз: ";
    in >> exc.pain;
    
    cout << "Время на лечение:  ";
    in >> exc.time;

    return in;
}
