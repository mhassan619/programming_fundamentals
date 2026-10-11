#include<iostream>
using namespace std;
void print(int a){
	cout<<"This is the integer function."<<endl;
	cout<<a<<endl;
}
void print(string a){
	cout<<"This function prints the string."<<endl;
	cout<<a<<endl;
}
void print(char a){
	cout<<"this function prints the character."<<endl;
	cout<<a<<endl;
}
void print(double a){
	cout<<"this function prints the double value."<<endl;
	cout<<a<<endl;
}
int main(){
	print(3);
	print("Hassan");
	print('A');
	print(30.3);
	return 0;
}
