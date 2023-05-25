#include "AccountList.h"

ACCOUNTSLIST::ACCOUNTSLIST() {}

void ACCOUNTSLIST::setAccountsList(vector<ACCOUNT *> accountsList)
{
    this->accountsList = accountsList;
}

vector<ACCOUNT *> ACCOUNTSLIST::getAccountsList()
{
    return accountsList;
}
int ACCOUNTSLIST::checkAccountUsername(string username)
{
    for (int i = 0; i < accountsList.size(); i++)
    {
        if (username == accountsList[i]->getUsername())
            return i;
    }
    return -1;
}
void ACCOUNTSLIST::inputAAcount(string idUser)
{
    ACCOUNT *TempAcc = new USER;
    TempAcc->input(idUser);
    accountsList.push_back(TempAcc);
}

bool ACCOUNTSLIST::checkDuplicatedUsername(string username)
{
    for (int i = 0; i < accountsList.size(); i++)
    {
        if (accountsList[i]->getUsername() == username)
        {
            return true;
        }
    }
    return false;
}

void ACCOUNTSLIST::readFile()
{
    ifstream inFile;
    inFile.open("Data Account.txt", ios::in);
    while (!inFile.eof())
    {
        int select;
        inFile >> select;
        ACCOUNT *Temporary;
        if (select == 1)
        {
            Temporary = new ADMIN;
        }
        else if (select == 2)
        {
            Temporary = new USER;
        }
        Temporary->readFileAAccount(inFile);
        accountsList.push_back(Temporary);
        inFile.ignore();
        if (inFile.eof())
        {
            break;
        }
    }
    inFile.close();
}

void ACCOUNTSLIST::exportFile()
{
    ofstream outFile;
    outFile.open("Data Account.txt", ios::out);
    for (int i = 0; i < accountsList.size(); i++)
    {
        if (i != accountsList.size() - 1)
        {
            accountsList[i]->exportFileAAccount(outFile);
            outFile << endl;
        }
        else
        {
            accountsList[i]->exportFileAAccount(outFile);
        }
    }
    outFile.close();
}

int ACCOUNTSLIST::checkAccount(string username, string password)
{
    for (int i = 0; i < accountsList.size(); i++)
    {
        if (username == accountsList[i]->getUsername() && password == accountsList[i]->getPassword())
        {
            return i;
        }
    }
    return -1;
}
void ACCOUNTSLIST::deleteAccount(string idpeople)
{
    for (int i = 0; i < accountsList.size(); i++)
    {
        if (accountsList[i]->getId() == idpeople)
        {
            accountsList.erase(accountsList.begin() + i);
        }
    }
}

ACCOUNTSLIST::~ACCOUNTSLIST() {}