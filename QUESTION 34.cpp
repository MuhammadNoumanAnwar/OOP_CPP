#include <iostream>
#include <string>
using namespace std;

class appliance{
	public :
		bool powerstatus = true;
		void setpower_status(){
			if(powerstatus == true){
				powerstatus = false;
				cout<<"truned off"<<endl;
				
			}
			else{
				powerstatus = true;cout<<"turned on"<<endl; 
			}
		}
};
class smartappliance:protected appliance{
	public :
		bool wificonnectivity= false;
		void setwifi(){
			if(wificonnectivity == true){
				wificonnectivity = false;
				cout<<"wifi off"<<endl;
			}
			else{
		    	wificonnectivity = true;cout<<"wifi on"<<endl; 
			}
		}
};
class smartlight:protected smartappliance{
	public :
		int brightness;
	void setbrightness(int level){
			brightness = level;
			cout<<"brightness level"<<" "<<brightness<<endl;
		}
		void status()
		{
			setpower_status();
			setwifi();
		}
};
int main(){
	smartlight l1;
	l1.status();
	l1.setbrightness(10);
	return 0;
}
		

