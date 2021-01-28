#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	cout << gcd(2,4);
}
