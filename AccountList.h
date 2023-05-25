#pragma once
#include "Account.h"
#include "Admin.h"
#include "User.h"
#include <vector>

class ACCOUNTSLIST
{
    private:
         vector<ACCOUNT*> accountsList;
    public:
        ACCOUNTSLIST();
        void setAccountsList(vector<ACCOUNT*>);
        vector<ACCOUNT*> getAccountsList();
        void inputAAcount(string);
        bool checkDuplicatedUsername(string);
        void readFile();
        void exportFile();
        int checkAccount (string username, string password);
        int checkAccountUsername(string username);
        void deleteAccount (string);
        ~ACCOUNTSLIST();
};