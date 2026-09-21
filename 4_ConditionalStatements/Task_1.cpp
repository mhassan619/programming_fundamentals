#include<iostream>
using namespace std;
int main(){
	int choice;
	cout<<"1.Add\n";
	cout<<"2.Delete\n";
	cout<<"3.Update\n";
	cout<<"4.Search\n";
	cout<<"5.Exit\n";
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"You are adding something."<<endl;
			break;
		case 2:
			cout<<"You are deleting something."<<endl;
			break;
		case 3:
			cout<<"You are going to update something."<<endl;
			break;
		case 4:
			cout<<"You are trying to Search something."<<endl;
			break;
		case 5:
			cout<<"You are exiting the website."<<endl;
			break;
		default:
			cout<<"Invalid command! Please use correct command."<<endl;
	}
	return 0;
}
