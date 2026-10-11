#include<iostream>
using namespace std;
bool isSorted(int arr[], int size){
	for(int i = 0; i < size - 1; i++){
		if(arr[i] > arr[i + 1]){
			return false;
		}
	}
	return true;
}
int main(){
	int array[] = {2, 4, 6, 7};
	int n = 4;
	cout<< isSorted(array,n);
	return 0;
}
