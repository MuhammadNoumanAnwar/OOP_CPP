#include <iostream>
#include <string>
using namespace std;

class counter 
{
    private:
    static int count;
    public :
    counter(){
        count++;
        getcount();
    }
        static void getcount()
        {
            cout<<"count "<<" "<<count<<endl;
        }
};
int counter::count = 0;
int main(){
   counter c1,c2,c3;
//   counter :: getcount();
   return 0;
}