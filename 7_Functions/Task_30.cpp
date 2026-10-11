#include<iostream>
#include<string>
using namespace std;
void change(string &s){
	s[0] = 'X';
}
int main(){
	string name = "Hassan";
	cout<<name<<endl;
	change(name);
	cout<<name<<endl;
	return 0;
}
