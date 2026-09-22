#include<iostream>
using namespace std;
int main(){
	int count_positive = 0;
	int count_negative = 0;
	int count_zero = 0;
	for(int i = 1; i <= 10; i++){
		int x;
		cin>>x;
		if(x > 0){
			count_positive++;
		} else if(x < 0){
			count_negative++;
		} else {
			count_zero++;
		}
	}
	cout<<"Positive Numbers: "<<count_positive<<endl;
	cout<<"Negative Numbers: "<<count_negative<<endl;
	cout<<"Zeros: "<<count_zero;
	return 0;
}
