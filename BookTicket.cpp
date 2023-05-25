#include "BookTicket.h"

BookTicket::BookTicket(){};
BookTicket::BookTicket(string idUser, int idBill, string trip, string departure, string detination, string playDay, string playReturn, int quantity, string seatClass, float unitPrice)
{
    this->idUser = idUser;
    this->idBill = idBill;
    this->trip = trip;
    this->departure = departure;
    this->detination = detination;
    this->playDay = playDay;
    this->playReturn = playReturn;
    this->quantity = quantity;
    this->seatClass = seatClass;
    this->unitPrice = unitPrice;
}
void BookTicket::setIdUser(string idUser)
{
    this->idUser = idUser;
}
string BookTicket::getIdUser()
{
    return idUser;
}
void BookTicket::setIdBill(int idBill)
{
    this->idBill = idBill;
}
int BookTicket::getIdBill()
{
    return idBill;
}
void BookTicket::setTrip(string trip)
{
    this->trip = trip;
}
string BookTicket::getTrip()
{
    return trip;
}
void BookTicket::setDeparture(string departure)
{
    this->departure = departure;
}
string BookTicket::getDeparture()
{
    return departure;
}
void BookTicket::setDetination(string)
{
    this->detination = detination;
}
string BookTicket::getDetination()
{
    return detination;
}
void BookTicket::setPlayDay(string)
{
    this->playDay = playDay;
}
string BookTicket::getPlayDay()
{
    return playDay;
}
void BookTicket::setPlayReturn(string playReturn)
{
    this->playReturn = playReturn;
}
string BookTicket::getPlayReturn()
{
    return playReturn;
}
void BookTicket::setQuantity(int quantity)
{
    this->quantity = quantity;
}
int BookTicket::getQuantity()
{
    return quantity;
}
void BookTicket::setUnitPrice(float unitPrice)
{
    this->unitPrice = unitPrice;
}
void BookTicket::setSeatClass(string seatClass)
{
    this->seatClass = seatClass;
}
string BookTicket::getSeatClass()
{
    return seatClass;
}
float BookTicket::getUnitPrice()
{
    return unitPrice;
}
int BookTicket::idTicket()
{
    int ramdom;
    ramdom = rand();
    return ramdom;
}

void BookTicket::readFileBookTicket(ifstream &inFile)
{
    char x;
    getline(inFile, this->idUser, ',');
    inFile >> this->idBill;
    inFile >> x;
    getline(inFile, this->trip, ',');
    getline(inFile, this->departure, ',');
    getline(inFile, this->detination, ',');
    getline(inFile, this->playDay, ',');
    getline(inFile, this->playReturn, ',');
    inFile >> this->quantity;
    inFile >> x;
    getline(inFile, this->seatClass, ',');
    inFile >> this->unitPrice;
    inFile.ignore();
}
void BookTicket::exportFileBookTicket(ofstream &outFile)
{
    idBill = idTicket();
    outFile << this->idUser << ",";
    outFile << idBill << ",";
    outFile << this->trip << ",";
    outFile << this->departure << ",";
    outFile << this->detination << ",";
    outFile << this->playDay << ",";
    outFile << this->playReturn << ",";
    outFile << this->quantity << ",";
    outFile << this->seatClass << ",";
    outFile << this->unitPrice << ",";
}

void BookTicket::input(ACCOUNTSLIST &acc, int index)
{
    this->idUser = acc.getAccountsList()[index]->getId();
    cout << "\n\n\t\t\t\tTRIP" << endl;
    cout << "\t\t\t\t1. One way"
         << "     "
         << "2. Round-trip" << endl;
    int selection;
    cout << "\t\t\t\tPlease enter your selection: ";
    cin >> selection;
    if (selection == 1)
    {
        trip = "One way";
    }
    if (selection == 2)
    {
        trip = "Round-trip";
    }
    cin.ignore();
    cout << "\t\t\t\tPoint of departure: ";
    getline(cin, departure);
    standardizeName(departure);
    cout << "\t\t\t\tDestination: ";
    getline(cin, detination);
    standardizeName(detination);
    cout << "\t\t\t\tDate of departure(DD/MM/YYYY): ";
    cin >> playDay;
    if (selection == 2)
    {
        cout << "\t\t\t\tDate of destination(DD/MM/YYYY): ";
        cin >> playReturn;
    }
    cout << "\t\t\t\tNumber of passengers: ";
    cin >> quantity;
    cout << "\t\t\t\tSeat class(Trader/Common): ";
    cin >> seatClass;
    standardizeName(seatClass);
    cout << "\t\t\t\tTicket price: ";
    cin >> unitPrice;
}
string BookTicket::getID()
{
    return this->idUser;
}
void BookTicket::output()
{
    cout << "\t\t\t\tCustomer ID: " << this->idUser << endl;
    cout << "\t\t\t\tBook Ticket ID: " << this->idBill << endl;
    cout << "\t\t\t\tOne way/ Round-trip: " << this->trip << endl;
    cout << "\t\t\t\tPoint of departure: " << this->departure << endl;
    cout << "\t\t\t\tDestination: " << this->detination << endl;
    cout << "\t\t\t\tDate of departure(DD/MM/YYYY): " << this->playDay << endl;
    cout << "\t\t\t\tDate of destination(DD/MM/YYYY): " << this->playReturn << endl;
    cout << "\t\t\t\tNumber of passengers: " << this->quantity << endl;
    cout << "\t\t\t\tSeat class(Trader/Common): " << this->seatClass << endl;
    cout << "\t\t\t\tTicket price: " << this->unitPrice << endl;
}
BookTicket::~BookTicket() {}