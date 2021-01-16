#include<iostream>
using namespace std;
int main(){
	int a,b;
	cin >> a >> b;
	if(b==2||b==5||b==8)cout << "200";
	else if(a%2)cout << "100";
	else if(a==b)cout << "50";
	else cout << "0";
	cout << endl;
} 
