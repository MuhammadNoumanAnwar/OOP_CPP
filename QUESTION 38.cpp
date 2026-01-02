#include <iostream>
#include <string>
using namespace std;

class Machine {
public:
    void powerOn() { cout << "Machine powered on.\n"; }
    void powerOff() { cout << "Machine powered off.\n"; }
};

class AI : virtual public Machine {
public:
    void analyzeEnvironment() { cout << "AI analyzing environment.\n"; }
};

class Mechanical : virtual public Machine {
public:
    void moveArms() { cout << "Moving arms.\n"; }
    void moveLegs() { cout << "Moving legs.\n"; }
};

class HumanoidRobot : public AI, public Mechanical {
public:
    void showCapabilities() {
        powerOn();
        analyzeEnvironment();
        moveArms();
        moveLegs();
        powerOff();
    }
};

int main() {
    HumanoidRobot h;
    h.showCapabilities();
    return 0;
}

