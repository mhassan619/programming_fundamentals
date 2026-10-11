#include<iostream>
using namespace std;
int countDigit(int n){
	if(n == 0){
		return 1;
	}
	int count = 0;
	while(n != 0){
		n /= 10;
		count++;
	}
	return count;
}
int main(){
	int n = 12368;
	cout<<countDigit(n);
	return 0;
}
