#include<iostream>
using namespace std;
int main(){
	int A,B;
	cin >> A >> B;
	if(A>B){
		cout << A << ">" << B;
	}else if(A<B){
		cout << A << "<" << B;
	}else{
		cout << A << "=" << B;
	}
	cout << endl;
} 
