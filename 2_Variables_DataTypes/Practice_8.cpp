#include<iostream>
using namespace std;
int main(){
	int seconds = 367;
	int minutes = seconds / 60;
	int remaining = seconds % 60;
	cout << minutes << " minutes  " << remaining<<" seconds ";
	return 0;
}
