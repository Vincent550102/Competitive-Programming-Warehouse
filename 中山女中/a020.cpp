#include<iostream>
using namespace std;
int main(){
	int a,b;
	cin >> a >> b;
	int ans = 0;
	if(b==2||b==5||b==8)ans+=200;
	if(a%2)ans+=100;
	if(a==b)ans+=50;
	cout << ans <<endl;
} 
