#include<bits/stdc++.h>
using namespace std;
int main(){
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n = 1000;
	cout << n << endl;
	for(int i = 0; i<n; i++){
		cout << rng()%1001 << " ";
	}
}

