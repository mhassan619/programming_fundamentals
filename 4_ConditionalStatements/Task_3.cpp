#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int maximum = a;
	int minimum = a;
	if(b > maximum){
		maximum = b;
	}
	if(c > maximum){
		maximum = c;
	}
	if(b < minimum){
		minimum = b;
	}
	if(c < minimum){
		minimum = c;
	}
	cout<<"Maximum is: "<<maximum<<endl;
	cout<<"Minimum is: "<<minimum<<endl;
	return 0;
}
