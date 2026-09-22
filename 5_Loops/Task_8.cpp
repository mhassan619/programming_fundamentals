#include<iostream>
using namespace std;
int main(){
	int x;
	cin>>x;
	int minimum = x;
	for(int i = 2; i<=5; i++){
		cin>>x;
		if(x < minimum){
			minimum = x;
		}
	}
	cout<<"Minimum value is: "<<minimum<<endl;
	return 0;
}
