#include "PeopleList.h"
PEOPLELIST::PEOPLELIST() {}
void PEOPLELIST::setPeopleList(vector<People *> PeopleList)
{
    this->PeopleList = PeopleList;
}
vector<People *> PEOPLELIST::getPeopleList()
{
    return this->PeopleList;
}
void PEOPLELIST::input(ACCOUNTSLIST &accountsList)
{
    system("cls");
    cout << "\t\t\t\tINPUT INFORMATION OF THE PEOPLE" << endl;
    People *Temporary;
    Temporary = new Customer;
    Temporary->input();
    do
    {
        if (checkDuplicatedIdPeople(Temporary->getId()) == true)
        {
            system("cls");
            cout << "\t\t\t\tINPUT INFORMATION OF THE PEOPLE" << endl;
            cout << "\t\t\t\tPlease re-enter this people identification: ";
            string Temp;
            cin >> Temp;
            Temporary->setId(Temp);
        }
    } while (checkDuplicatedIdPeople(Temporary->getId()) == true);
    accountsList.inputAAcount(Temporary->getId());
    
    PeopleList.push_back(Temporary);
    cout << "\n\t\t\t\tInput information succesfully!! Press any key to continue. . .";
}
void PEOPLELIST::output()
{
    for (int i = 0; i < PeopleList.size(); i++)
    {
        cout << "\n\t\t\t\tInformation Of The People" << i + 1 << "\n";
        PeopleList[i]->output();
    }
}
void PEOPLELIST::outputCustomer()
{
    for (int i = 0; i < PeopleList.size(); i++)
    {
        PeopleList[i]->output();
    }
}
void PEOPLELIST::outputManager()
{
    for (int i = 0; i < PeopleList.size(); i++)
    {
        PeopleList[i]->output();
    }
}
void PEOPLELIST::outputAllPeople()
{
    for (int i = 0; i < PeopleList.size(); i++)
    {
        PeopleList[i]->output();
    }
}
bool PEOPLELIST::checkDuplicatedIdPeople(string idpeople)
{
    for (int i = 0; i < PeopleList.size(); i++)
    {
        if (PeopleList[i]->getId() == idpeople)
        {
            return true;
        }
    }
    return false;
}

int PEOPLELIST::findPeopleById(string idpeopele)
{
    for (int i = 0; i < PeopleList.size(); i++)
    {
        if (PeopleList[i]->getId() == idpeopele)
        {
            return i;
        }
    }
    return -1;
}
void PEOPLELIST::findPeopleByName(string name)
{
    bool Check = false;
    for (int i = 0; i < PeopleList.size(); i++)
    {
        string temp = PeopleList[i]->getName();
        if (temp == name)
        {
            cout << "\n\t\t\t\tFOLLOWING IS ALL THE INFORMATION ABOUT READER YOU ARE LOOKING FOR" << endl;
            PeopleList[i]->output();
            Check = true;
        }
    }
    if (Check == false)
    {
        cout << "\n\t\t\t\tSORRY!!! THE READER WHOSE INFORMATION YOU ARE LOOKING FOR DOESN'T EXIST!!!";
        cout << "\n\t\t\t\tPLEASE TRY AGAIN!";
    }
}
void PEOPLELIST::deletePeopleById(string idpeople)
{
    for (int i = 0; i < PeopleList.size(); i++)
    {
        if (PeopleList[i]->getId() == idpeople)
        {
            PeopleList.erase(PeopleList.begin() + i);
            cout << "\n\t\t\t\tDelete reader successfully!!! Press any key to continue. . .";
            return;
        }
    }
    cout << "\n\t\t\t\tNot found this reader!!! Press any key to continue. . .";
}

void PEOPLELIST::readFile()
{
    ifstream inFile;
    inFile.open("Data People.txt", ios::in);
    while (!inFile.eof())
    {
        int select;
        inFile >> select;
        People *Temporary;
        if (select == 1)
        {
            Temporary = new Manager;
        }
        else if (select == 2)
        {
            Temporary = new Customer;
        }
        Temporary->readFilePeople(inFile);
        PeopleList.push_back(Temporary);
        inFile.ignore();
        if (inFile.eof())
        {
            break;
        }
    }
    inFile.close();
}
void PEOPLELIST::exportFile()
{
    ofstream outFile;
    outFile.open("Data People.txt", ios::out);
    for (int i = 0; i < PeopleList.size(); i++)
    {
        if (i != PeopleList.size() - 1)
        {
            PeopleList[i]->exportFilePeople(outFile);
            outFile << endl;
        }
        else
        {
            PeopleList[i]->exportFilePeople(outFile);
        }
    }
    outFile.close();
}
PEOPLELIST::~PEOPLELIST() {}
