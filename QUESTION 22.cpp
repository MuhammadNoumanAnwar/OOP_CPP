//Design a UserProfile class to manage social media users with attributes name, age, and
//email. Implement a default constructor that sets default values, a parameterized
//constructor for custom initialization, a copy constructor for duplicating profiles, and a
//constructor with default arguments where only the name is required while age and
//email default to preset values. Test by creating user objects using all constructor
//variants and displaying their details.
#include <iostream>
#include <string>
using namespace std;
class socialmedia{
    string name;
    int age;
    string email;
    public :
    	socialmedia()
    	{
    		name = "xyz";
    		age = 0 ;
    		email = "xyz@gmail.com";
    		cout<<"default called"<<endl;
		}
		socialmedia(string nam,int ag ,string mail):name(nam),age(ag),email(mail){
		cout<<"parameterized called";
		}
		
		socialmedia(socialmedia &s1){
			s2= *s1;
		}
		socialmedia(string name)
		{
			this->name=name;
			age=s1.age;
			email=s1.email;
		}
};
	int main(){
		socialmedia s2;
		socialmedia s1("nouman" , 18 , "nouman@gmail.com");
		socialmedia s2(s1);
		socialmedia s1("nouman");
		return 0;
	}