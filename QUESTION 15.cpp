#include <iostream>
#include <cmath>  
using namespace std;

class Vector2D {
    private:
        float x,y;  
    public:
        Vector2D(float xVal=0,float yVal=0) {
            x=xVal;
            y=yVal;
        }

        void display() const {
            cout << "Vector(" << x <<", "<<y<<")"<< endl;
        }

        Vector2D operator+(const Vector2D& v) const {
            return Vector2D(x+v.x,y+v.y);
        }
        bool operator==(const Vector2D& v) const {
            const float EPSILON=0.0001;  
            return(fabs(x-v.x)<EPSILON) && (fabs(y-v.y)<EPSILON);
        }
};
int main() {
    Vector2D v1(1,2);
    Vector2D v2(3,4);
    Vector2D v3(5,6);

    Vector2D result=v1+v2+v3;

    cout << "Resultant Vector: ";
    result.display();

    Vector2D expected(9,12);
    if (result==expected) {
        cout<<"Vectors are equal!"<<endl;
    } 
    else {
        cout<<"Vectors are NOT equal!"<<endl;
    }
    return 0;
}