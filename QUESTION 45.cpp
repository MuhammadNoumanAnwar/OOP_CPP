#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount, exchangeRate;
    string currencyCode, currencySymbol;

public:
    Currency(double amt, string code, string symbol, double rate = 1.0)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() const { return amount * exchangeRate; }
    virtual void displayCurrency() const { cout << currencySymbol << amount << " (" << currencyCode << ")" << endl; }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
    double convertToBase() const override { return amount * exchangeRate; }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "E", 1.1) {}
    double convertToBase() const override { return amount * exchangeRate; }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "Rs", 0.012) {}
    double convertToBase() const override { return amount * exchangeRate; }
};

int main() {
    Dollar d(100);
    Euro e(100);
    Rupee r(100);

    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();

    cout << "Dollar in base: " << d.convertToBase() << endl;
    cout << "Euro in base: " << e.convertToBase() << endl;
    cout << "Rupee in base: " << r.convertToBase() << endl;

    return 0;
}
