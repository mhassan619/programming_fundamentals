#include<iostream>
using namespace std;
int add(int a, int b){
	cout<<"This is the int function."<<endl;
	return a + b;
}
double add(double a, double b){
	cout<<"This is double function."<<endl;
	return a + b;
}
int main(){
	cout<<add(2,5)<<endl;
	cout<<add(2.5,7.5)<<endl;
	cout<<add(10,30)<<endl;
	return 0;
}
