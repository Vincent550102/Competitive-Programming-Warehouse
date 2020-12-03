#include<bits/stdc++.h>
using namespace std;
int main(){
	int a = 2;
	int t;
	while(cin >> a){
		int o = 1<<a;
		cout << o << endl;
		t |= 1<<a;
		cout << t << endl;
	}
}
