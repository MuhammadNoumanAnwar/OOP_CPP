//Q2. An Autonomous Vehicle system requires multiple capabilities:
//? Vehicle (Base Class): Attributes like speed and move().
//? AI_System (Base Class): Provides navigate() and detectObstacles().
//? SelfDrivingCar (Derived Class): Inherits both Vehicle and AI_System capabilities.
//Task:
//1. Implement the classes using multiple inheritance.
//2. Create a SelfDrivingCar object and demonstrate its functionality.
//3. Handle ambiguity if methods with the same name exist in Vehicle and AI_System.
#include <iostream>
#include <string>
using namespace std;
class vehicle{
	public :
		int speed;
		void move(int s){
			speed = s;
			cout<<"speed"<<" "<<speed<<endl;
		}
};
class ai_system {
	public :
		void move(){
			cout<<"move 10km turn right move 15km stop"<<endl;
		}
		void detectobstacles(){
			cout<<"obstacle detected"<<endl;
		}
};
class selfdrivingcar:protected vehicle , protected ai_system{
	public :
		void movevehicle(int s){
			vehicle::move(s);
		}
		void display(){
		ai_system::move();
		detectobstacles();
		}
};
int main(){
	selfdrivingcar c1;
	c1.movevehicle(128);
	c1.display();
	return 0;
}
