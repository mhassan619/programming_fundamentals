#include<iostream>
using namespace std;
void change(int &x){
	x = 100;
	cout<<"Value inside function: "<<x<<endl;
}
int main(){
	int a = 10;
	change(a);
	cout<<"Value outside the function: "<<a;
	return 0;
}
