//Create a function int find_second_largest(int arr[], int size) to find and return the second-largest element
//in a 1D array.
#include <iostream>
using namespace std;
find_second_largest(int arr[], int size){
	int max=0,s_max=0;
	for(int i=0 ; i<size ;i++){
		if(arr[i]>=max){
			max = arr[i];
		}
	}
		for(int i=0 ; i<size ;i++){
		if(arr[i]!=max && arr[i]>s_max){
			s_max = arr[i];
		}
	}
	return s_max;
}
int main(){
	int array[] = { 213 , 443 , 5 , 7 , 876 , 0 , 93 };
	int size = sizeof(array) / sizeof(array[0]);
	cout<<"Second largest "<<find_second_largest(array,size);
return 0;
}

