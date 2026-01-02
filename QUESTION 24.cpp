#include <iostream>
#include <string>
using namespace std;
class userprofile
{
private:
    string name;
    int *age;
    string email_id;

public:
    userprofile()
    {
        cout << "i am default constructor" << endl;
        name = "XYZ";
        email_id = "xyz@.gmail.com";
        age = 0;
    }

    userprofile(string name, int age, string email_id)
    {
        cout << "i am parameterised constructor" << endl;
        this->name = name;
        this->age = new int(age);
        this->email_id = email_id;
    }
    userprofile(const userprofile &s)
    {
        cout << "i am copy constructor" << endl;
        age = new int(*(s.age));
        name = s.name;
        email_id = s.email_id;
    }
    userprofile(string name)
    {
        cout << "i am constructor with name as parimeter" << endl;
        this->name = name;
        age = new int(0);
        email_id = "xyz@.gmail.com";
    }
    void display()
    {
        cout << "display function called" << endl;
        cout << name << " " << *age << " " << email_id << " " << "address->" << age << endl;
    }
    ~userprofile()
    {
        cout << "i am destructor" << endl;
        delete age;
    }
};
int main()
{
    userprofile s1("usman", 18, "usman@123gmail.com");
    s1.display();
    userprofile s2(s1);
    s2.display();
    userprofile s4("nouman");
    s4.display();
    s1.display();
    s2.display();
    userprofile s3(s2);
    s3.display();
    userprofile s5;
    return 0;
}
