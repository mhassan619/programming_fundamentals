#include<iostream>
using namespace std;
int arraySum(int arr[], int n){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += arr[i];
	}
	return sum;
}
int main(){
	int arr[] = {23,45,15,17};
	int result = arraySum(arr,4);
	cout<<result;
	return 0;
}
