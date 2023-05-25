#include "Account.h"

ACCOUNT::ACCOUNT() {}
ACCOUNT::ACCOUNT(string username, string password) {
    this->username = username;
    this->password = password;
}
void ACCOUNT::setUsername(string username) {
    this->username = username;
}
string ACCOUNT::getUsername() {
    return username;
}
void ACCOUNT::setPassword(string password) {
    this->password = password;
}
string ACCOUNT::getPassword() {
    return password;
}
ACCOUNT::~ACCOUNT() {}