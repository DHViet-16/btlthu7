#pragma once
#include <iostream>
#include "BookTicket.h"
#include <vector>
#include <fstream>
#include <string.h>
using namespace std;

class BookTicketList
{
private:
    vector<BookTicket> bookticketslist;
public:
    BookTicketList();
    void setBookTicketList(vector<BookTicket>);
    vector<BookTicket> getBookTicketList();
    void input(ACCOUNTSLIST&, int);
    void output();
    int findBookTicketById(string);
    void readFile();
    void exportFIle();
    ~BookTicketList();
};