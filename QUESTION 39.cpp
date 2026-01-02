#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    int health;
public:
    Character(int h) : health(h) {}
    void attack() { cout << "Character attacking.\n"; }
};

class Mage : virtual public Character {
public:
    Mage(int h) : Character(h) {}
    void castSpell() { cout << "Mage casting spell.\n"; }
};
class Warrior : virtual public Character {
public:
    Warrior(int h) : Character(h) {}
    void useSword() { cout << "Warrior using sword.\n"; }
};
class BattleMage : public Mage, public Warrior {
public:
    BattleMage(int h) : Character(h), Mage(h), Warrior(h) {}
    void showAbilities() {
        attack();
        castSpell();
        useSword();
    }
};
int main() {
    BattleMage bm(100);
    bm.showAbilities();
    return 0;
}

