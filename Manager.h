#ifndef Manager_h
#define Manager_h
#include "People.h"
#include "Function.h"

class Manager: public People
{
    public:
    Manager();
    Manager(string ,string ,string ,int , string ,string ,string );
    void input();
    void output();
    void readFilePeople(ifstream &inFile);
    void exportFilePeople(ofstream &outFile);
    ~Manager();
};
#endif 