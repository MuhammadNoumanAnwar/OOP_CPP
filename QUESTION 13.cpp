#include <iostream>
using namespace std;

class Item {
private:
    string name;
    double price;

public:
    Item(string n, double p) {
        name = n;
        price = p;
    }

    friend class StoreManager;
    friend double applyDiscount(Item& i, double percent);
    
    string getName() const { return name; }
    double getPrice() const { return price; }
};

double applyDiscount(Item& i, double percent) {
    i.price -= (i.price * percent / 100);
    return i.price;
}

class Bundle {
private:
    Item item1, item2;

public:
    Bundle(Item i1, Item i2) : item1(i1), item2(i2) {}

    Bundle operator+(const Bundle& b) {
        string newName = item1.getName() + " & " + b.item1.getName();
        double newPrice = item1.getPrice() + b.item1.getPrice();
        return Bundle(Item(newName, newPrice), item2);
    }

    void showBundle() {
        cout << "Bundle contains: " << item1.getName() << " and " << item2.getName() << endl;
        cout << "Total Price: PKR " << item1.getPrice() + item2.getPrice() << endl;
    }
};

class StoreManager {
public:
    void printItemDetails(Item i) {
        cout << "Item: " << i.name << ", Price: PKR " << i.price << endl;
    }
};

int main() {
    Item item1("Laptop", 280000);
    Item item2("Headphones", 30000);
    StoreManager manager;

    cout << "Before Discount:" << endl;
    manager.printItemDetails(item1);
    manager.printItemDetails(item2);

    applyDiscount(item1, 10);
    cout << "\nAfter 10% Discount on Laptop:" << endl;
    manager.printItemDetails(item1);

    Bundle bundle1(item1, item2);
    Bundle bundle2(Item("Mouse", 5000), Item("Keyboard", 8000));

    Bundle mergedBundle = bundle1 + bundle2;

    cout << "\nBundle 1 details: " << endl;
    bundle1.showBundle();

    cout << "\nMerged Bundle details: " << endl;
    mergedBundle.showBundle();

    return 0;
}
