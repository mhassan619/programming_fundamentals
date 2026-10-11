#include<iostream>
using namespace std;
int arraySum(int arr[], int index, int n){
	if(index == n){
		return 0;
	}
	return arr[index] + arraySum(arr, index + 1, n);
}
int main(){
	int array[] = {1,2,3,4,5};
	cout<<arraySum(array,0,5);
	return 0;
}
