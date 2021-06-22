#include <iostream>
#include "list.h"
#include "appfunction.h"

using namespace std;
int main(int argc, char * argv[]){
    if (argc < 1){
        cout << "Error" << endl;
        return 0;

    }
    List list;
    AppFunction fl;
    fl.ReadFile(argv[1], &list);
    int flag = 1;

    while (flag!=0){
        fl.DrawMenu();
        cin >> flag;

        if (flag==1){
            list.AddNew();
        }

        else if (flag==2){
            list.Print();
        }

        else if (flag==3){
            cout << "Количество пациентов: " << list.Size() << endl;
        }

        else if (flag==4){
            int del_index;
            cout << "Пациент №: ";
            cin >> del_index;
            cout << endl;
            list.Del(del_index);
        }

        else if (flag==5){
            int value;
            cout << "1) сортировать по имени" << endl;
            cout << "2) сортировать по диагнозу/заболеванию" << endl;
            cout << "3) сортировать по времени лечения" << endl;
            cin >> value;
            fl.SortList(&list, value, 1);
        }

        else if (flag==6){
            int value;
            cout << "1) сортировать по имени" << endl;
            cout << "2) сортировать по диагнозу/заболеванию" << endl;
            cout << "3) сортировать по времени лечения" << endl;
            cin >> value;
            fl.SortList(&list, value, 0);
        }

        else if (flag==7){
            int value;
            cout << "1) Поиск по имени " << endl;
            cout << "2) Поиск по диагнозу/заболеванию " << endl;
            cout << "3) Поиск по времени лечения" << endl;
            cin >> value;
            fl.Search(&list, value);
        }

        else if (flag==8){
            int value;
            cout << "Пациент №: ";
            cin >> value;
            cout << "1) Изменить имя пациента" << endl;
            cout << "2) Изменить диагнозу/заболеванию" << endl;
            cout << "3) Изменить время лечения" << endl;
            cout << "Введите число от 1 до 4: " << endl;
            fl.Change(&list, value - 1);
        }


        else if (flag==0){
            fl.WriteFile(argv[1], &list);
            return 0;
        }
    }

    return 0;
}
