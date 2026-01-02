#include <iostream>
#include <string>

using namespace std;

class RentalCar
{
private:
    string model;
    int rentalID;
    double pricePerDay;

public:
    RentalCar(string model, int rentalID, double pricePerDay)
    {
        cout << "Parameterized constructor" << endl;
        this->model = model;
        this->rentalID = rentalID;
        this->pricePerDay = pricePerDay;
    }
    RentalCar(const RentalCar &other)
    {
        cout << "Copy constructor" << endl;
        model = other.model;
        rentalID = other.rentalID;
        pricePerDay = other.pricePerDay;
    }
    ~RentalCar()
    {
        cout << "Destructor called for rental ID: " << rentalID << endl;
    }
    double calculateTotal(int days) const
    {
        return pricePerDay * days;
    }
    void displayDetails() const
    {
        cout << "Car Model: " << model << "\nRental ID: " << rentalID << "\nPrice per Day: " << pricePerDay << endl;
    }
};
int main()
{
    RentalCar car1("Toyota", 1001, 40.00);
    car1.displayDetails();
    cout << "Total cost for 5 days: " << car1.calculateTotal(5) << endl;
    cout << "\nCopying rental car" << endl;
    RentalCar car2 = car1;
    car2.displayDetails();

    return 0;
}