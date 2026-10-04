#include<iostream>
using namespace std;
void value(int x){
	x = 100;
}
void reference(int &x){
	x = 200;
}
int main(){
	int a = 10;
	cout<<"A before value and reference function: "<<a<<endl;
	value(a);
	cout<<"A after value function and before reference function: "<<a<<endl;
	reference(a);
	cout<<"A before reference function: "<<a<<endl;
	return 0;
}
