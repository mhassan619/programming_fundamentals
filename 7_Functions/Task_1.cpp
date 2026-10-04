#include<iostream>
using namespace std;
// We have to atleast declare function 
// if we want to complete add function after main function with its definition
int add(int a, int b);          
int main(){
	int result = add(5,6);
	cout<<result;
	return 0;
}
int add(int a, int b){
	return a + b;
}
