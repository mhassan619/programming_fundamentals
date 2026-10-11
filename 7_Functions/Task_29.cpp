#include<iostream>
#include<string>
using namespace std;
bool isPallindrome(string s){
	int left = 0;
	int right = s.length() - 1;
	while(left < right){
		if(s[left] != s[right]){
			return false;
		}
		left++;
		right--;
	}
	return true;
}
int main(){
	string name = "racecar";
	cout<<isPallindrome(name);
	return 0;
}
