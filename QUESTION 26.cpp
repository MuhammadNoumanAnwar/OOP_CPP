#include <iostream>
#include <string>
using namespace std;

class smartdevice
{
    string name;
    string type;
    string status;

public:
    smartdevice(string name, string type, string status)
    {

        cout << "parameterized constructor" << endl;
        this->name = name;
        this->type = type;
        this->status = status;
    }
    ~smartdevice()
    {
        cout << "destructor called" << endl;
    }
};
int main()
{
    smartdevice s1("moblie", "electronic", "on");
    smartdevice s2(s1);
    smartdevice s3("oven", "electronic", "off");
    return 0;
}
