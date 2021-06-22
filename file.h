#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include "list.h"

class File
{
public:
    File();
    void ReadFile(char *f, List *l);
    void WriteFile(char *f, List *l);
};

#endif // FILE_H
