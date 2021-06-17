#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll a,b,c;
	cin >> a >> b >> c;
	if(c&1){//odd
		cout << (a==b?"=":a>b?">":"<");
	}else{//even
		cout << (abs(a)==abs(b)?"=":abs(a)>abs(b)?">":"<");
	}
	cout << endl;
}
