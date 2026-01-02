#include <iostream>
using namespace std;

struct Rectangle {
    double length, width;
};

double area(Rectangle* r) {
    return r->length * r->width;
}

double perimeter(Rectangle* r) {
    return 2 * (r->length + r->width);
}

int main() {
    Rectangle r = { 5, 3 };
    cout << area(&r) << endl;
    cout << perimeter(&r) << endl;
}

