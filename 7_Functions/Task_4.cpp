#include<iostream>
using namespace std;
void change(int x){
	x = 100;
	cout<<"Value inside the function "<<x<<endl;
}
int main(){
	int a = 10;
	change(a);
	cout<<"Value outside the function ";
	cout<<a;
	return 0;
}
