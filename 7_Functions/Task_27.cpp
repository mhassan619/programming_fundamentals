#include<iostream>
#include<string>
using namespace std;
void reverseString(string s){
	for(int i = s.length() - 1; i >= 0; i--){
		cout<<s[i];
	}
}
int main(){
	string name = "Hassan";
	reverseString(name);
	return 0;
}
