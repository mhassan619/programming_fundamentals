#include<iostream>
using namespace std;
int main(){
	double x = 5.5;
    int y = 2;
	cout << x + y; 
	cout<<"\n";
	char ch = 'A';
    cout << ch;
    cout<<"\n";
    char ch1 = '7';
    cout<<static_cast<int>(ch1)<<"\n";
    cout<<static_cast<int>('0')<<"\n";
	int x1 = ch1 - '0';
	cout << x1;
	return 0;
}
