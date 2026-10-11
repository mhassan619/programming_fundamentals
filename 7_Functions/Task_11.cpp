#include<iostream>
using namespace std;
int x = 100;
void change(){
	x = 200;
}
int main(){
	cout<<"Before change function: "<<x<<endl;
	change();
	cout<<"After change function: "<<x<<endl;
	return 0;
}
