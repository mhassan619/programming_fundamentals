#include<iostream>
using namespace std;
bool search(int arr[], int n, int target){
	for(int i = 0; i < n; i++){
		if(arr[i] == target){
			return true;
		}
	}
	return false;
}
int main(){
	int array[] = {23,45,667,232,78,90};
	int target = 2;
	int size = sizeof(array) / sizeof(array[0]);
	cout<< search(array,size,target);
	return 0;
}
