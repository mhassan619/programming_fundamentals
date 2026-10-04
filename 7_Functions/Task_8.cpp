#include<iostream>
using namespace std;
void calculate(int a, int b, int &sum, int &product){
	sum = a + b;
	product = a * b;
}
int main(){
	int sum; 
	int product;
	calculate(5,4,sum,product);
	cout<<sum<<" "<<product<<endl;
	return 0;
}
