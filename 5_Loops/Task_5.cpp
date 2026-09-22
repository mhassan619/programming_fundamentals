#include<iostream>
using namespace std;
int main(){
	int sum = 0;
	for(int i = 1; i <= 5; i++){
		int x;
		cin>>x;
		sum+=x;
	}
	cout<<"Sum of users entered numbers: "<<sum<<endl;
	return 0;
}
