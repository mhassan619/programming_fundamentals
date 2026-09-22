#include<iostream>
using namespace std;
int main(){
	int x; 
	cin>>x;
	int maximum = x;
	for(int i = 2; i <= 5; i++){
		cin>>x;
		if(x > maximum){
			maximum = x;
		}
	}
	cout<<"Maximum Value is: "<<maximum<<endl;
	return 0;
}
