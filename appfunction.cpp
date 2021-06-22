#include "appfunction.h"

AppFunction::AppFunction(){}

void AppFunction::Change(List *l, int index)
{
    Patient * finded = l->Find(index);
    if (finded==nullptr){
        return;
    }
    int opt;
    cin >> opt;
    switch(opt){
        case(1):
            {
                cout << "Введите новое имя пациента: ";
                string n;
                cin >> n;
                finded->SetName(n);
            }
            break;

        case(2):
            {
                cout << "Введите новое заболевание/диагноз: ";
                string p;
                cin >> p;
                finded->SetPain(p);
            }
            break;

        case(3):
            {
                cout << "Введите новую длительность лечения: ";
                int t;
                cin >> t;
                finded->SetTime(t);
            }
            break;


    }
    return;

}
void AppFunction::Search(List *l, int value)
{
    string n, p;
    int t;

    if (value == 1){
        cout <<"Искомое имя пациента: " <<endl;
        cin >> n;
    }
    else if(value == 2){
        cout << "Искомое заболевание/диагноз: ";
        cin >> p;
    }

    else if(value == 3){
        cout << "Искомое количество времени: ";
        cin >> t;
    }

    Patient *tmp = l->GetHead();
    int size = l->Size();

    for (int i = 0; i< size; i++){
        if (value == 1){
            if (tmp->GetName() == n){
                cout << "Пациент " << i  << endl;
                cout << *tmp << endl;

            }
        }
        else if(value == 2){
            if (tmp->GetPain() == p){
                cout << "Пациент" << i  << endl;
                cout << *tmp << endl;

            }
        }
        else if(value == 3){
            if (tmp->GetTime() == t){
                cout << "Пациент" << i  << endl;
                cout << *tmp << endl;

            }
        }

        tmp = tmp->GetNext();
    }
}

void AppFunction::DrawMenu()
{
    cout << "\n" << endl;
    cout << "1) Добавить пациента         " << endl;
    cout << "2) Вывести список пациентов   " << endl;
    cout << "3) Колличество пациентов      " << endl;
    cout << "4) Выписать пациента          " << endl;
    cout << "5) Сортировать по возростанию " << endl;
    cout << "6) Сортировать по убыванию    " << endl;
    cout << "7) Поиск                      " << endl;
    cout << "8) Изменить                   " << endl;
    cout << "0) выйти                      " << endl;
    cout << endl;
    cout << "Введите число от 0 до 8 ->" << endl;
}
