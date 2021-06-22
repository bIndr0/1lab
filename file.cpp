#include "file.h"

File::File(){}

void File::ReadFile(char *f, List *l)
{
    fstream out(f, ios::in);
    if (!out.is_open()){
        cout << "file didnt open" << endl;
        return;
    }
    string n,p;
    int t,size;
    out >> size;
    Patient* tmp;
    for (int i=0; i<size; i++){
        out >> n;
        out >> p;
        out >> t;
        l->Push();
        l->GetHead()->SetName(n);
        l->GetHead()->SetPain(p);
        l->GetHead()->SetTime(t);
    }
    out.close();
}

void File::WriteFile(char *f, List *l)
{
    fstream in(f, ios::out);
    if (!in.is_open()){
            cout << "file didnt open" << endl;
            return;
    }
    string n, p;
    int t;
    Patient *tmp = l->GetHead();

    in << l->Size() << endl;

    while(tmp != nullptr){
        n = tmp->GetName();
        p = tmp->GetPain();
        t = tmp->GetTime();

        in << n <<endl;
        in << p << endl;
        in << t << endl;

        tmp = tmp->GetNext();
    }
    in.close();
}
