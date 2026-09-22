//Count digits
 
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int count = 0;
	if(n == 0){
		count = 1;
	} else {
		while(n > 0){
			count++;
			n /= 10;
		}
	}
	cout<<"No. of digits: "<<count<<endl;
	return 0;
}
