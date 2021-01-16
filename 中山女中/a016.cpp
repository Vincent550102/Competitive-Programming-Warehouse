#include<iostream>
using namespace std;
int main(){
	int N;
	cin >> N;
	if((!(N%4)&&(N%100))||!(N%400)){
		cout << "YES";
	}else{
		cout << "NO";
	}
	cout << endl;
} 
