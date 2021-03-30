#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,k;cin >> n >> k;
	string str; cin >> str;
	int cnt = 0;
	for(int i = 0; i<n/2; i++){
		if(str[i]!=str[n-i-1])cnt++;
	}
	cout << abs(cnt-k) << endl;
}

int main(){
	int t;cin >> t;for(int i = 1; i<=t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
}
