#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n > 0){
		if(n % 2 == 0){
			cout<<"Number is positive even."<<endl;
		} else {
			cout<<"Number is positive odd."<<endl;
		}
	} else if (n < 0){
		if(n % 2 == 0){
			cout<<"Number is negative even."<<endl;
		} else {
			cout<<"Number is negative odd."<<endl;
		}
	} else {
		cout<<"Number is 0"<<endl;
	}
	return 0;
}
