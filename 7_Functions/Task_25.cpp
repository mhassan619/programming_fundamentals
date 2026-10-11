#include<iostream>
#include<string>
using namespace std;
int countVowels(string s){
	int count = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U'){
			count++;
		}
	}
	return count;
}
int main(){
	string name;
	getline(cin,name);
	cout<<"Vowels in "<<name<<" : "<<countVowels(name);
	return 0;
}
