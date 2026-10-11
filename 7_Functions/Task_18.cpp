#include<iostream>
using namespace std;
int findMax(int arr[], int n){
	int maximum = arr[0];
	for(int i = 1; i < n; i++){
		if(arr[i] > maximum){
			maximum = arr[i];
		}
	}
	return maximum;
}
int main(){
	int arr[] = {23,56,77,21,88,99,45,67,23,25,43};
	int size = sizeof(arr) / sizeof(arr[0]);
    cout<< "Maximum: "<<findMax(arr,size);
    return 0;
}
