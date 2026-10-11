#include<iostream>
#include<string>
using namespace std;
bool isPallindrome(string s, int left, int right){
	if(left >= right){
		return true;
	}
	if(s[left] != s[right]){
		return false;
	}
	return isPallindrome(s,left + 1, right - 1);
}
int main(){
	string name = "madam";
	cout<<isPallindrome(name, 0 ,name.length() - 1);
	return 0;
}
