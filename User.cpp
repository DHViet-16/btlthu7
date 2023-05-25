#include "User.h"

USER::USER() {}

USER::USER(string username, string password, string idUser) : ACCOUNT(username, password)
{
    this->idUser = idUser;
}

void USER::setIdUser(string idUser)
{
    this->idUser = idUser;
}

string USER::getIdUser()
{
    return idUser;
}

int USER::getFormat()
{
    return 2;
}
void USER::input(string idUser)
{
    cout << "\n\t\t\t\tEnter username: ";
    getline(cin, username);
    string pass, comfirmPass;
    cout << "\n\t\t\t\tEnter password: ";
    getline(cin, pass);
    cout << "\n\t\t\t\tRe-Enter password to comfirm: ";
    getline(cin, comfirmPass);
    do
    {
        if (comfirmPass != pass)
        {
            cout << "\n\t\t\t\tINCORRECT PASSWORD!";
            cout << "\n\t\t\t\tPlease re-enter your password to comfirm : ";
            comfirmPass.clear();
            getline(cin, comfirmPass);
        }
    } while (comfirmPass != pass);

    this->password = pass;
    this->idUser = idUser;
}

string USER::getId()
{
    return this->idUser;
}

void USER::readFileAAccount(ifstream &inFile)
{
    char x;
    inFile >> x;
    getline(inFile, this->username, ',');
    getline(inFile, this->password, ',');
    getline(inFile, this->idUser, ',');
}

void USER::exportFileAAccount(ofstream &outFile)
{
    outFile << 2 << ",";
    outFile << this->username << ",";
    outFile << this->password << ",";
    outFile << this->idUser << ",";
}
void USER::changePassword(string _password)
{
    this->password = _password;
}
void USER::changeUserName(string _userName)
{
    this->username = _userName;
}
USER::~USER() {}