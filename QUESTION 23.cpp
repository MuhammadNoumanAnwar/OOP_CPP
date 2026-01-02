//Develop a SmartDevice class to represent home automation devices with attributes
//device name, type, and status (on/off). Implement a parameterized constructor for
//initialization and a destructor that prints a message when the device is destroyed. Test
//by creating and deleting objects, observing the destructor call when they go out of
//scope.
#include <iostream>
#include <string>
using namespace std;

class smartdevice {
	string name;
	string type;
	string status;
	public :
	smartdevice(string name, string type,string status):name(name),type(type),status(status){}
	~smartdevice(){	cout<<"destructor called "<<endl;	}
};
int main()
{
	smartdevice s1("fridge" , "house hold" , "on");
	smartdevice s2(s1);
	smartdevice s3("oven" , "house hold" , "off");
	return 0;
}
