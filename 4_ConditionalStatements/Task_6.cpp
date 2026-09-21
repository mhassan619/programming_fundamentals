#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a + b > c && a + c > b && c + b > a){
		cout<<"Triangle is valid."<<endl;
	} else {
		cout<<"Triangle is not valid."<<endl;
	} 
	return 0;
}
