#include<iostream>
using namespace std;
int main(){
	int count = 0;
	for(int i = 1; i <= 200; i++){
		if(i % 6 == 0 && i % 8 == 0){
			count++;
		}
	}
	cout<<"Digit counts that are divisible by 6 and 8 both till 200: "<<count;
	return 0;
}
