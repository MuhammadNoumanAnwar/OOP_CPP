//Q3. A University Management System has different entities:
//? Person (Base Class): Attributes name and age.
//? Employee (Derived from Person): Adds salary.
//? Student (Derived from Person): Adds rollNumber.
//? TeachingAssistant (Derived from both Employee and Student): Has subject
//specialization.
//Task:
//1. Implement the classes using hybrid inheritance.
//2. Demonstrate how TeachingAssistant handles data from both Employee and Student.
//3. Address any ambiguity caused by multiple inheritance.
#include <iostream>
#include <string>
using namespace std;
class person{
	public :
		string name;
		int age;
};
class employee:protected virtual person{
	public :
		float salary;
		void addsalary(float s){
			salary = s;
		}
};
class student:protected virtual person{
	public :
		string rollnumber;
		void addrollnumber(string r_no){
			rollnumber = r_no;
		}
}; 
class teachingassistant:protected employee,protected student{
	public :
		string subject;
		void addsubject(string sub){
			subject = sub;
		}
		void set(string n,int a,float s,string r , string sub){
			name = n;
			age = a;
			addsalary(s);
			addrollnumber(r);
			addsubject(sub);
		}
		void display() {
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
			cout << "Salary: " << salary << endl;
			cout << "Roll Number: " << rollnumber << endl;
			cout << "Subject: " << subject << endl;
		}
};
int main(){
	teachingassistant t1;
	t1.set("usman", 18, 5000, "TA-1234", "oop");
	t1.display();
	return 0;
}
