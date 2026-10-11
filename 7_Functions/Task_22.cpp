#include<iostream>
#include<string>
using namespace std;
int lengthOfString(string s){
	return s.length();
}
int main(){
	string name = "Hassan";
	cout<<"Length of Hassan: "<<lengthOfString(name)<<endl;
	return 0;
}
