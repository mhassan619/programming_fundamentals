#include<iostream>
using namespace std;
int main(){
	int x; 
	cin>>x;
	int max = x;
	int min = x;
	for(int i = 2; i<=10; i++){
		cin>>x;
		if(x > max){
			max = x;
		}
		if(x < min){
			min = x;
		}
	}
	cout<<"Maximum number: "<<max<<endl;
	cout<<"Minimum number: "<<min<<endl;
	return 0;
}
