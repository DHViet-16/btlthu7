#pragma once
#include "Account.h"
#include "AccountList.h"

using namespace std;

class USER : public ACCOUNT
{
private:
    string idUser;

public:
    USER();
    USER(string, string, string);
    void setIdUser(string);
    string getIdUser();
    string getId();
    int getFormat();
    void input(string);
    void readFileAAccount(ifstream &);
    void exportFileAAccount(ofstream &);
    void changePassword(string _password);
    void changeUserName(string _userName);
    ~USER();
};