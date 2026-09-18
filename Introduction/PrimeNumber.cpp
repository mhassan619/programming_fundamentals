#include<iostream>
using namespace std;
bool isPrime(int n){
	if(n < 2){
		return false;
	}
	for(int i = 2; i * i <= n - 1; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	if(isPrime(n)){
		cout<<"Prime Number";
	} else {
		cout<<"Not Prime";
	}
	return 0;
}
