#include<iostream>
using namespace std;
int main(){
	bool isPrime = true;
	int n; 
	cin>>n;
	if(n < 2){
		isPrime = false;
	} else {
		for(int i = 2; i * i <= n; i++){
			if(n % i == 0){
				isPrime = false;
				break;
			}
		}
	}
	if(isPrime){
		cout<<"Number is Prime."<<endl;
	} else {
		cout<<"Number is not Prime"<<endl;
	}
	return 0;
}
