#include<iostream>
using namespace std;
int main(){
	int marks;
	char grade;
	cin>>marks;
	if(marks < 0 || marks > 100){
		cout<<"Invalid marks"<<endl;
		return 0;
	} else if(marks >= 90){
		grade = 'A';
	} else if(marks >= 80){
		grade = 'B';
	} else if(marks >= 70){
		grade = 'C';
	} else if(marks >= 60){
		grade = 'D';
	} else {
		grade = 'F';
	}
	if(grade == 'F'){
		cout<<"You are fail"<<endl;
	} else {
		cout<<"Your grade is: "<<grade<<endl;
	}
	return 0;
}
