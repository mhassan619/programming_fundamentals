#include<iostream>
using namespace std;
void swapValue(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
int main(){
	int x = 10;
	int y = 20;
	cout<<"X: "<<x<<" Y: "<<y<<endl;
	swapValue(x,y);
	cout<<"X: "<<x<<" Y: "<<y<<endl;
	return 0;
}
