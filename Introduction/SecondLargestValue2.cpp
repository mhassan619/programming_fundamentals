#include<iostream>
using namespace std;
void secondLargest(int arr[],int size){
	int largest = INT_MIN;
	int secondlargest = INT_MIN;
	for(int i = 0; i<size; i++){
		if(arr[i] > largest){
			secondlargest = largest;
			largest = arr[i];
		} else if(arr[i] > secondlargest && arr[i] != largest){
			secondlargest = arr[i];
		}
	}
	cout<<"Largest Number is: "<<largest<<endl;
	cout<<"Second Largest Number is: "<<secondlargest<<endl;
}
int main(){
	int array[] = {11,22,59,77,43,23,55,29,35,56};
	int size = sizeof(array)/sizeof(array[0]);
	secondLargest(array,size);
	return 0;
}
