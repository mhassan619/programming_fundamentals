//#include<iostream>
//using namespace std;
//int main(){
//	int n = 0; 
//	for(int i = 1; i <= 5; i++){
//		for(int j = 5; j >= i; j--){
//			cout<<char('A' + n);
//			n++;
//		}
//		n = 0;
//		cout<<endl;
//	}
//	return 0;
//}

// Better and optimized way
#include<iostream>
using namespace std;
int main(){
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 5 - i + 1; j++){
			cout<<char('A' + j - 1);
		}
		cout<<endl;
	}
	return 0;
}
