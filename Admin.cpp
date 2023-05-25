#include "Admin.h"

ADMIN::ADMIN() {}

ADMIN::ADMIN(string username, string password, string idAdmin) : ACCOUNT(username, password) {
    this->idAdmin = idAdmin;
}

void ADMIN::setIdAdmin(string idAdmin) {
    this->idAdmin = idAdmin;
}

string ADMIN::getId() {
    return this->idAdmin;
}

string ADMIN::getIdAdmin() {
    return idAdmin;
}

int ADMIN::getFormat() {
    return 1;
}

void ADMIN::input(string idAdmin) {
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
            cout << "\n\t\t\t\tPlease re-enter your password to comfirm: ";
            comfirmPass.clear();
            getline(cin, comfirmPass);
        }
    } while (comfirmPass != pass);
    this->password = pass;
	this->idAdmin = idAdmin;
}

void ADMIN::readFileAAccount(ifstream &inFile) {
    char x;
    inFile >> x;
    getline(inFile, this->username, ',');
    getline(inFile, this->password, ',');
    getline(inFile, this->idAdmin, ',');
}

void ADMIN::exportFileAAccount(ofstream &outFile) {
    outFile << 1 << ",";
    outFile << this->username << ",";
    outFile << this->password << ",";
    outFile << this->idAdmin << ",";
}

void ADMIN::changePassword(string password) {
    this -> password = password;
}

void ADMIN::changeUserName(string username) {
    this -> username = username;
}

ADMIN::~ADMIN(){}