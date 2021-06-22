#include "sort.h"

Sort::Sort(){}

void Sort::SortList(List *l, int value, int opt)
{
    if (value > 5){
        printf("Error");
        return;
    }
    Patient *tmp = l->GetHead();
    Patient *header = l->GetHead();
    int n = l->Size();

    for (int i=0;i<n-1;i++){
        Patient *max = tmp;
        Patient *first_tmp = tmp;

        for (int j=i+1;j<n;j++){
            max = Sort::Compare(max, tmp, opt, value -1);
            tmp = tmp->GetNext();
        }
        max = Sort::Compare(max, tmp, opt, value - 1);
        l->Swap(first_tmp, max);
        tmp = max->GetNext();
        if (i==0){
            header = max;
        }
    }
    l->SetHead((header));
}

Patient *Sort::Compare(Patient *tmp, Patient *tmp_next, int opt,int  value)
{
    if (value == 0){
        return Sort::CompareName(tmp, tmp_next, opt);
    }
    else if (value == 1){
        return Sort::ComparePain(tmp, tmp_next, opt);
    }
    else if (value ==2){
        return Sort::CompareTime(tmp, tmp_next, opt);
    }
    else{
        return tmp;
    }
}

Patient *Sort::CompareName(Patient * tmp, Patient *tmp_next, int opt)
{
    if (((tmp->GetName() >= tmp_next->GetName()) && (opt==1)) || ((tmp->GetName() < tmp_next->GetName()) && (opt==0))){
        return tmp;
    }
    else{
        return tmp_next;
    }
}

Patient *Sort::ComparePain(Patient * tmp, Patient *tmp_next, int opt)
{
    if (((tmp->GetPain() >= tmp_next->GetPain()) && (opt==1)) || ((tmp->GetPain() < tmp_next->GetPain()) && (opt==0))){
        return tmp;
    }
    else{
        return tmp_next;
    }
}

Patient *Sort::CompareTime(Patient * tmp, Patient *tmp_next, int opt)
{
    if (((tmp->GetTime() >= tmp_next->GetTime()) && (opt==1)) || ((tmp->GetTime() < tmp_next->GetTime()) && (opt==0))){
        return tmp;
    }
    else{
        return tmp_next;
    }
}

