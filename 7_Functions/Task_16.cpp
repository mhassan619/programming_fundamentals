#include<iostream>
using namespace std;
void changeFirst(int arr[]){
	arr[0] = 100;
}
int main(){
	int arr[] = {10,20,30};
	cout<<"First Element before function call: "<<arr[0]<<endl;
	changeFirst(arr);
	cout<<"First Element after function call: "<<arr[0]<<endl;
	return 0;
}
