#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
    double position[2];

public:
    Shape(string col, double x, double y) : color(col) { position[0] = x; position[1] = y; }

    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual void draw() const = 0;
};

class Circle : public Shape {
    double radius;

public:
    Circle(string col, double x, double y, double r) : Shape(col, x, y), radius(r) {}

    double calculateArea() const override { return M_PI * radius * radius; }
    double calculatePerimeter() const override { return 2 * M_PI * radius; }
    void draw() const override { cout << "Drawing Circle" << endl; }
};

class Rectangle : public Shape {
    double width, height;

public:
    Rectangle(string col, double x, double y, double w, double h)
        : Shape(col, x, y), width(w), height(h) {}

    double calculateArea() const override { return width * height; }
    double calculatePerimeter() const override { return 2 * (width + height); }
    void draw() const override { cout << "Drawing Rectangle" << endl; }
};

class Triangle : public Shape {
    double sideA, sideB, sideC;

public:
    Triangle(string col, double x, double y, double a, double b, double c)
        : Shape(col, x, y), sideA(a), sideB(b), sideC(c) {}

    double calculateArea() const override {
        double s = (sideA + sideB + sideC) / 2;
        return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }
    double calculatePerimeter() const override { return sideA + sideB + sideC; }
    void draw() const override { cout << "Drawing Triangle" << endl; }
};

int main() {
    Circle c("Red", 0, 0, 5);
    Rectangle r("Blue", 1, 16, 4, 6);
    Triangle t("Green", 2, 6, 3, 6, 2);

    c.draw();
    cout << "Circle Area: " << c.calculateArea() << ", Perimeter: " << c.calculatePerimeter() << endl;

    r.draw();
    cout << "Rectangle Area: " << r.calculateArea() << ", Perimeter: " << r.calculatePerimeter() << endl;

    t.draw();
    cout << "Triangle Area: " << t.calculateArea() << ", Perimeter: " << t.calculatePerimeter() << endl;

    return 0;
}
