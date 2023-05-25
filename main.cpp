#include <iostream>
#include <vector>
#include <string.h>
#include "AccountList.h"
#include "Admin.h"
#include "User.h"
#include "PeopleList.h"
#include "BookTicketList.h"
#include "Function.h"

ACCOUNTSLIST accountsList;
PEOPLELIST PeopleList;
BookTicketList bookticketslist;

using namespace std;

void showMainMenuAdmin()
{
    system("cls");
    cout << "\n\t\t\t\t+----------------------------------------+";
    cout << "\n\t\t\t\t|           QUAN LY VE MAY BAY           |";
    cout << "\n\t\t\t\t+----------------------------------------+";
    cout << "\n\n";
    cout << "\n\t\t\t\t+-----------------------------------------+";
    cout << "\n\t\t\t\t|               MENU MANAGER              |";
    cout << "\n\t\t\t\t+-----------------------------------------+";
    cout << "\n\t\t\t\t|          1. Output All Ticket           |";
    cout << "\n\t\t\t\t|          2. Change your user name       |";
    cout << "\n\t\t\t\t|          3. Change your password        |";
    cout << "\n\t\t\t\t|          4. Book Ticket                  |";
    cout << "\n\t\t\t\t|          5. Check your ticket           |";
    cout << "\n\t\t\t\t+-----------------------------------------+";
    cout << "\n\t\t\t\t|          Press 000 to log out           |";
    cout << "\n\t\t\t\t+-----------------------------------------+";
}
void showMainMenuUser()
{
    system("cls");
    cout << "\n\t\t\t\t+----------------------------------------+";
    cout << "\n\t\t\t\t|           QUAN LY VE MAY BAY           |";
    cout << "\n\t\t\t\t+----------------------------------------+";
    cout << "\n\n";
    cout << "\n\t\t\t\t+-----------------------------------------+";
    cout << "\n\t\t\t\t|              MENU CUSTOMER              |";
    cout << "\n\t\t\t\t+-----------------------------------------+";
    cout << "\n\t\t\t\t|        1. Output your information       |";
    cout << "\n\t\t\t\t|        2. Change your user name         |";
    cout << "\n\t\t\t\t|        3. Change your password          |";
    cout << "\n\t\t\t\t|        4. Book Ticket                   |";
    cout << "\n\t\t\t\t|        5. Check your ticket             |";
    cout << "\n\t\t\t\t+-----------------------------------------+";
    cout << "\n\t\t\t\t|        Press 000 to log out             |";
    cout << "\n\t\t\t\t+-----------------------------------------+";
}
void showExitMenu()
{
    cout << "\n\n";
    cout << "\t\t\t\t\tHAVE A GREAT WORKING DAY";
    cout << "\n\t\t\t\tTHANK YOU AND SEE YOU SOON" << endl;
}
void menuAdmin(int index)
{
    while (true)
    {
        showMainMenuAdmin();
        int selection;
        cout << "\n\t\t\t\tPLEASE ENTER YOUR SELECTION: ";
        cin >> selection;
        cin.ignore();
        if (selection == 1)
        {
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 1 (OUTPUT ALL TICKET)\n";
            bookticketslist.output();
            system("pause");
        }
        if (selection == 2)
        {
            system("cls");
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 2 (CHANGE YOUR USER NAME)\n";
            string newUserName;
            cout << "\n\t\t\t\tEnter your new user name: ";
            getline(cin, newUserName);
            do
            {
                if (accountsList.checkDuplicatedUsername(newUserName) == true)
                {
                    cout << "\n\t\t\t\tDUPLICATED USER NAME ERROR!";
                    cout << "\n\t\t\t\tPlease re-enter your new user name: ";
                    getline(cin, newUserName);
                }
            } while (accountsList.checkDuplicatedUsername(newUserName) == true);
            accountsList.getAccountsList()[index]->changeUserName(newUserName);
            accountsList.exportFile();
            cout << "\n\t\t\t\tChange username successfully! Press any key to continue. . .";
            getch();
            break;
        }
        if (selection == 3)
        {
            system("cls");
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 3 (CHANGE YOUR PASSWORD)\n";
            string oldPassword;
            cout << "\n\t\t\t\tEnter your old password: ";
            cin >> oldPassword;
            if (accountsList.getAccountsList()[index]->getPassword() != oldPassword)
            {
                cout << "\n\t\t\t\tINCORRECT PASSWORD!";
                cout << "\n\t\t\t\tPlease re-enter your old password: ";
                cin >> oldPassword;
            }
            string newPassword;
            cout << "\n\t\t\t\tEnter your new password: ";
            cin >> newPassword;
            if (accountsList.getAccountsList()[index]->getPassword() == newPassword)
            {
                cout << "\n\t\t\t\tNEW PASSWORD MUST BE DIFFERENT WITH OLD PASSWORD!";
                cout << "\n\t\t\t\tPlease re-enter your new password: ";
                cin >> newPassword;
            }
            accountsList.getAccountsList()[index]->changePassword(newPassword);
            accountsList.exportFile();
            cout << "\n\t\t\t\tChange password successfully! Press any key to continue. . .";
        }
        if (selection == 4)
        {
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 4 (BOOK TICKET)\n";
            bookticketslist.input(accountsList, index);
            bookticketslist.exportFIle();
        }
        if (selection == 5)
        {
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 5 (CHECK YOUR TICKET)\n";
            string accountId = accountsList.getAccountsList()[index]->getId(); // Lấy ID của tài khoản
            for (int i = 0; i < bookticketslist.getBookTicketList().size(); i++)
            {
                if (bookticketslist.getBookTicketList()[i].getID()==accountId)
                {
                    bookticketslist.getBookTicketList()[i].output();
                    cout << "\t\t\t\t-------------------------------" << endl;
                }
            }
            system("\t\t\t\tpause");
        }
        if (selection == 000)
        {
            cout << "\n\t\t\t\tDo you want to log out? [Yes/No]: ";
            string answer;
            getline(cin, answer);
            standardizeName(answer);
            if (answer == "Yes")
            {
                showExitMenu();
                break;
            }
        }
    }
}
void menuUser(int index)
{
    while (true)
    {
        showMainMenuUser();
        int selection;
        cout << "\n\t\t\t\tPLEASE ENTER YOUR SELECTION: ";
        cin >> selection;
        cin.ignore();
        if (selection == 1)
        {
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 1 (OUTPUT YOUR INFORMATION)\n";
            PeopleList.getPeopleList()[PeopleList.findPeopleById(accountsList.getAccountsList()[index]->getId())]->output();
            cout << "\n\t\t\t\tPress any key to return to MENU . . .";
            getch();
        }
        if (selection == 2)
        {
            system("cls");
            cout << "\n\t\t\t\tYOU HAVE CHOSE OPTION 2 (CHANGE YOUR USER NAME)\n";
            string newUserName;
            cout << "\n\t\t\t\tEnter your new user name: ";
            getline(cin, newUserName);
            do
            {
                if (accountsList.checkDuplicatedUsername(newUserName) == true)
                {
                    cout << "\n\t\t\t\tDUPLICATED USER NAME ERROR!";
                    cout << "\n\t\t\t\tPlease re-enter your new user name: ";
                    getline(cin, newUserName);
                }
            } while (accountsList.checkDuplicatedUsername(newUserName) == true);
            accountsList.getAccountsList()[index]->changeUserName(newUserName);
            accountsList.exportFile();
            cout << "\n\t\t\t\tChange username successfully! Press any key to continue. . .";
            getch();
            break;
        }
        if (selection == 3)
        {
            system("cls");
            cout << "\n\t\t\t\tYOU HAVE CHOSE OPTION 3 (CHANGE YOUR PASSWORD)\n";
            string oldPassword;
            cout << "\n\t\t\t\tEnter your old password: ";
            cin >> oldPassword;
            if (accountsList.getAccountsList()[index]->getPassword() != oldPassword)
            {
                cout << "\n\t\t\t\tINCORRECT PASSWORD!";
                cout << "\n\t\t\t\tPlease re-enter your old password: ";
                cin >> oldPassword;
            }
            string newPassword;
            cout << "\n\t\t\t\tEnter your new password: ";
            cin >> newPassword;
            if (accountsList.getAccountsList()[index]->getPassword() == newPassword)
            {
                cout << "\n\t\t\t\tNEW PASSWORD MUST BE DIFFERENT WITH OLD PASSWORD!";
                cout << "\n\t\t\t\tPlease re-enter your new password: ";
                cin >> newPassword;
            }
            accountsList.getAccountsList()[index]->changePassword(newPassword);
            accountsList.exportFile();
            cout << "\n\t\t\t\tChange password successfully! Press any key to continue. . .";
            getch();
            break;
        }
        if (selection == 4)
        {
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 4 (BOOK TICKET)\n";
            bookticketslist.input(accountsList, index);
            bookticketslist.exportFIle();
        }
        if (selection == 5)
        {
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 5 (CHECK YOUR TICKET)\n";
            string accountId = accountsList.getAccountsList()[index]->getId(); // Lấy ID của tài khoản
            for (int i = 0; i < bookticketslist.getBookTicketList().size(); i++)
            {
                if (bookticketslist.getBookTicketList()[i].getID()==accountId)
                {
                    bookticketslist.getBookTicketList()[i].output();
                    cout << "\t\t\t\t-------------------------------" << endl;
                }
            }
            system("\t\t\t\tpause");
        }
        if (selection == 000)
        {
            cout << "\n\t\t\t\tDo you want to log out? [Yes/No]: ";
            string answer;
            getline(cin, answer);
            standardizeName(answer);
            if (answer == "Yes")
            {
                showExitMenu();
                break;
            }
        }
    }
}
int passAccount()
{
    string username, password;
    cout << "\n\t\t\t\tEnter your username: ";
    cin >> username;
    cout << "\n\t\t\t\tEnter your password: ";
    cin >> password;
    if (accountsList.checkAccount(username, password) != -1)
        return accountsList.checkAccount(username, password);
    return -1;
}
void signup()
{
    PeopleList.input(accountsList);
    PeopleList.exportFile();
    accountsList.exportFile();
}
int main()
{
    PeopleList.readFile();
    bookticketslist.readFile();
    accountsList.readFile();
    while (true)
    {
        system("cls");
        cout << "\n\t\t\t\t  +----------------------------------------+";
        cout << "\n\t\t\t\t  |           QUAN LY VE MAY BAY           |";
        cout << "\n\t\t\t\t  +----------------------------------------+";
        cout << endl;
        cout << "\n\t\t\t\t+------------+"
             << "                 "
             << "+-------------+";
        cout << "\n\t\t\t\t|  1. LOGIN  |"
             << "                 "
             << "|  2.SIGN UP  |";
        cout << "\n\t\t\t\t+------------+"
             << "                 "
             << "+-------------+";
        int option;
        cout << "\n\t\t\t\tPLEASE ENTER YOUR OPTION: ";
        cin >> option;
        if (option == 2)
        {
            signup();
        }
        system("cls");
        cout << "\n\t\t\t\t  +----------------------------------------+";
        cout << "\n\t\t\t\t  |           QUAN LY VE MAY BAY           |";
        cout << "\n\t\t\t\t  +----------------------------------------+";
        int index = passAccount();
        if (index != -1)
        {
            cout << "\n [ANNOUNCEMENT] Login successfully! Press any key to continue!";
            if (accountsList.getAccountsList()[index]->getFormat() == 1)
            {
                menuAdmin(index);
                //                system("pause");
            }
            else
            {
                menuUser(index);
            }
        }
        else
        {
            cout << "\n\t\t\t\t YOUR ACCOUNT ISN'T EXISTING! PLEASE CONTACT ADMINISTRATOR TO CREATE AN ACOUNT NOW!\n [ANNOUNCEMENT] ";
            system("pause");
        }
    }
    return 0;
}
