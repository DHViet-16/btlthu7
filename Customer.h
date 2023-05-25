#pragma once
#include "People.h"
#include "Function.h"
class Customer: public People
{
    public:
    Customer();
    Customer(string , string ,string ,int , string,  string , string );
    void input();
    void output();
    void readFilePeople(ifstream &inFile);
    void exportFilePeople (ofstream &outFile);
    ~Customer();
};