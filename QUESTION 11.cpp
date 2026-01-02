#include "Restaurant.h"
#include <iostream>
using namespace std;


Restaurant::Restaurant(string name) : name(name){}

string Restaurant::getName() const {
    return name;
}

double Restaurant::getRating() const {
    return rating;
}

class FastFood : public Restaurant {
public:
    FastFood(string name) : Restaurant(name) {}

    void processOrder(const string& item) override {
        cout << "FastFood: Processing order for " << item << " instantly.\n";
    }

    void updateRating(double newRating) override {
        rating = newRating;
        cout << "FastFood: Rating updated to " << rating << endl;
    }
};

class FineDining : public Restaurant {
private:
    string chefName;

public:
    FineDining(string name, string chefName) : Restaurant(name), chefName(chefName) {}

    void processOrder(const string& item) override {
        cout << "FineDining: Processing order for " << item << ". This will take some time. Chef: " << chefName << "\n";
    }

    void updateRating(double newRating) override {
        rating = newRating;
        cout << "FineDining: Rating updated to " << rating << endl;
    }
};

class Cafe : public Restaurant {
private:
    string beverageType;
    int brewingTime;

public:
    Cafe(string name, string beverageType, int brewingTime) : Restaurant(name), beverageType(beverageType), brewingTime(brewingTime) {}

    void processOrder(const string& item) override {
        cout << "Cafe: Brewing a " << beverageType << " for " << item << ". This will take " << brewingTime << " minutes.\n";
    }

    void updateRating(double newRating) override {
        rating = newRating;
        cout << "Cafe: Rating updated to " << rating << endl;
    }
};

int main() {
    FastFood fastFood("Zinger");
    FineDining fineDining("Le Gourmet", "Chef Burak");
    Cafe cafe("The Brew House", "Coffee", 5);

    fastFood.processOrder("Burger");
    fineDining.processOrder("Steak");
    cafe.processOrder("Latte");

    fastFood.updateRating(4.2);
    fineDining.updateRating(4.8);
    cafe.updateRating(4.5);

    return 0;
}
