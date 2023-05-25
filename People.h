#pragma once
#include <iostream>
#include <cstring>
#include<fstream>
#include<string>
#include <vector>
using namespace std;

class People
{
protected:
    string ID;
    string name;
    string sex;
    int age;
    string phone;
    string email;
    string address;
public:
    People();
    People(string , string ,string ,int , string,  string , string );
    void setId(string );
    string getId();
    void setName(string);
    string getName();
    void setSex(string);
    string getSex();
    void setAge(int);
    int getAge();
    void setPhone(string);
    string getPhone();
    void setEmail(string);
    string getEmail();
    void setAdress(string);
    string getAdress();
    virtual void input() = 0;
    virtual void output() = 0;
    virtual void readFilePeople(ifstream &) = 0;
    virtual void exportFilePeople(ofstream &) = 0;
    ~People();
};