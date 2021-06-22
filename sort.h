#ifndef SORT_H
#define SORT_H
#include "list.h"

class Sort
{
public:
    Sort();
    void SortList(List *l, int value, int opt);
    Patient* CompareName(Patient * tmp, Patient *tmp_next, int opt);
    Patient* ComparePain(Patient * tmp, Patient *tmp_next, int opt);
    Patient* CompareTime(Patient * tmp, Patient *tmp_next, int opt);
    Patient* Compare(Patient * tmp, Patient *tmp_next, int opt, int value);
};

#endif // SORT_H
