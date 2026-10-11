#include<iostream>
using namespace std;
int power(int base, int exponent = 2){
	int result = 1;
	for(int i = 1; i <= exponent; i++){
		result *= base;
	}
	return result;
}
int main(){
	cout<<power(5);
	return 0;
}
