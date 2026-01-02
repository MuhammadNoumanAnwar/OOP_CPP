#include <iostream>
using namespace std;

class Engine
{
public:
    int horsepower;
    string type;

    Engine(int hp, string t) : horsepower(hp), type(t) {}
};

class Car
{
public:
    string brand;
    Engine engine;

    Car(string b, int hp, string t) : brand(b), engine(hp, t) {}

    void display()
    {
        cout << "Car Brand: " << brand << "\nEngine: " << engine.horsepower << " HP, Type: " << engine.type << endl;
    }
};

int main()
{
    Car car("Toyota", 156, "Petrol");
    car.display();
    return 0;
}
