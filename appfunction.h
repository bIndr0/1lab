#ifndef APPFUNCTION_H
#define APPFUNCTION_H
#include "list.h"
#include "sort.h"
#include "file.h"
class AppFunction: public Sort, public File
{
public:
    AppFunction();
    void Search(List *l, int value);
    void Change(List *l, int index);
    void DrawMenu();
};

#endif // APPFUNCTION_H
