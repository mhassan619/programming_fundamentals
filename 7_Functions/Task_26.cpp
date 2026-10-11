#include<iostream>
#include<string>
using namespace std;
int countCharacter(string s, char target){
	int count = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == target){
			count++;
		}
	}
	return count;
}
int main(){
	string name = "Hassan";
	cout<<"A's in "<<name<<": "<<countCharacter(name,'a');
	return 0;
}
