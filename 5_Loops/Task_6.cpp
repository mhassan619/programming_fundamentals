#include<iostream>
using namespace std;
int main(){
	int count = 0;
	for(int i = 1; i <= 5; i++){
		int x; 
		cin>>x;
		if(x > 0){
			count++;
		}
	}
	cout<<"Positive numbers are: "<<count;
	cout<<"\nNegative numbers are: "<<5 - count;
	return 0;
}
