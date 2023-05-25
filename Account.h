#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

class ACCOUNT
{
    protected:
        string username;
        string password;
    public:
        ACCOUNT();
        ACCOUNT(string, string);
        void setUsername(string);
        string getUsername();
        void setPassword(string);
        string getPassword();
        virtual int getFormat() = 0; // 1 is admin and 2 is user
        virtual void input(string) = 0;
        virtual void readFileAAccount(ifstream &) = 0;
        virtual void exportFileAAccount(ofstream &) = 0;
        virtual string getId() = 0;
        virtual void changeUserName(string) = 0;
        virtual void changePassword(string) = 0;
        ~ACCOUNT();
};