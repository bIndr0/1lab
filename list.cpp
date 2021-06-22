#include "list.h"
List::List()
{
   head = nullptr;
   size = 0;

}

List::~List()
{
    Patient *tmp = head;
    while(tmp != nullptr){
        Patient *p = tmp;
        tmp = tmp->GetNext();
        delete p;
    }
}

Patient* List::GetHead()
{
    return head;
}

void List::SetHead(Patient *h)
{
    head = h;
}

void List::Print()
{
    Patient *tmp = head;
    for (int i = 0; i<size; i++){
        cout << "Пациент " << i+1  << endl;
        cout << *tmp << endl;
        tmp = tmp->GetNext();
    }
}

void List::Push()
{
    Patient *tmp = new Patient();
    tmp->SetNext(head);
    tmp->SetPrev(nullptr);
    if (head != nullptr){
        head->SetPrev(tmp);
    }
    head = tmp;
    size++;

    return;
}

Patient* List::Find(int index){
    Patient * finded = nullptr, * tmp = head;
    int i = 0;
    while(tmp != nullptr) {
        if(i == index) {
            finded = tmp;
            break;
        }
        i++;
        tmp = tmp->GetNext();
    }
    return finded;
}

void List::Del(int index)
{
    Patient * finded = List::Find(index-1);

    if(finded == nullptr){
        return;
    }

    if(finded->GetPrev()) {
        finded->GetPrev()->SetNext(finded->GetNext());
    }

    if(finded->GetNext()) {
        finded->GetNext()->SetPrev(finded->GetPrev());
     }

     if (index == 1){
        head = finded->GetNext();
        delete(finded);
        size--;
     }

     else{
        size--;
        delete(finded);
     }
}

int List::Size()
{
    return size;
}

void List::AddNew()
{
    List::Push();
    cin >> *head;
}

void List::Swap(Patient *left, Patient *rigth)
{
    Patient * t_next = left->GetNext();
    Patient * t_prev = left->GetPrev();


    Patient * ti_next = rigth->GetNext();
    Patient * ti_prev = rigth->GetPrev();

    if ((left->GetNext() != rigth) && (left->GetPrev() != rigth)){
        rigth->SetNext(t_next);
        rigth->SetPrev(t_prev);


        if (t_next){
            t_next->SetPrev(rigth);
        }

        if (t_prev){
            t_prev->SetNext(rigth);
        }


        left->SetNext(ti_next);
        left->SetPrev(ti_prev);

        if (ti_next){
            ti_next->SetPrev(left);
        }
        if (ti_prev){
            ti_prev->SetPrev(left);
        }
    }
    else{
        left->SetNext(ti_next);
        left->SetPrev(rigth);

        if (ti_next){
            ti_next->SetPrev(left);
        }

        rigth->SetNext(left);
        rigth->SetPrev(t_prev);


        if (t_prev){
            t_prev->SetNext(rigth);
        }
    }
}
