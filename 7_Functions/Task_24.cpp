#include<iostream>
#include<string>
using namespace std;
void printChars(string s){
	for(int i = 0; i < s.length(); i++){
		cout<< s[i] <<" ";
	}
}
int main(){
	string name = "HELLO";
	printChars(name);
	return 0;
}
