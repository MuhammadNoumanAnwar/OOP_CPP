#include <iostream>
#include <string>
using namespace std;
class MovieTicket
{
private:
    string name;
    int seatNumber;
    double price;
    string status;

public:
    MovieTicket()
    {
        cout << "Default constructor" << endl;
        name = "Unknown";
        seatNumber = 0;
        price = 0.0;
        status = "Available";
    }
    MovieTicket(string name, int seatNumber, double price, string status)
    {
        cout << "Parameterized constructor" << endl;
        this->name = name;
        this->seatNumber = seatNumber;
        this->price = price;
        this->status = status;
    }
    MovieTicket(const MovieTicket &other)
    {
        cout << "Copy constructor" << endl;
        name = other.name;
        seatNumber = other.seatNumber;
        price = other.price;
        status = other.status;
    }
    MovieTicket &operator=(const MovieTicket &other)
    {
        cout << "Assignment operator" << endl;
        if (this != &other)
        {
            name = other.name;
            seatNumber = other.seatNumber;
            price = other.price;
            status = other.status;
        }
        return *this;
    }

    ~MovieTicket()
    {
        cout << "Destructor called for seat: " << seatNumber << endl;
    }
    void cancelBooking()
    {
        status = "Canceled";
        cout << "Booking for seat " << seatNumber << " has been canceled." << endl;
    }

    void displayTicket() const
    {
        cout << "Movie: " << name << "\nSeat: " << seatNumber << "\nPrice: " << price << "\nStatus: " << status << endl;
    }
};
int main()
{
    MovieTicket ticket1("Fast", 12, 15.50, "Booked");
    ticket1.displayTicket();
    cout << "\nCancelling ticket..." << endl;
    ticket1.cancelBooking();
    ticket1.displayTicket();
    cout << "\nCopying ticket..." << endl;
    MovieTicket ticket2 = ticket1;
    ticket2.displayTicket();
    cout << "\nAssigning ticket..." << endl;
    MovieTicket ticket3;
    ticket3 = ticket1;
    ticket3.displayTicket();
    return 0;
}