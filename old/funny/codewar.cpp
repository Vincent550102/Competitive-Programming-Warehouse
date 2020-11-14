#include<bits/stdc++.h>
#define pi 3.141592653
#define e 2.718281828
#define lb long double
using namespace std;
int main(){
	lb t;
	cin >> t;
	
	cout <<setprecision(8)<<	pow(e,-t) * cos(2*pi*t);
}
