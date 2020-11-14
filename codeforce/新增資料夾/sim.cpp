#include<bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e2+5;

void solve(){
	int a[mxN],b[mxN],c[mxN];
	int n;cin >> n;
	for(int i = 0; i<n; i++){
		cin >> a[i];
	}
	for(int i = 0; i<n; i++){
		cin >> b[i];
	}
	for(int i = 0; i<n; i++){
		cin >> c[i];
	}
	int pre = -1;
	for(int i = 0; i<n-1; i++){
		if(pre!=a[i]){
			pre = a[i];
			cout << a[i];
		}else{
			pre = b[i];
			cout << b[i];
		}
		cout << " ";
	}
	if(a[n-1]==pre){
		if(b[n-1]==a[0]){
			cout << c[n-1];
		}else{
			cout << b[n-1];
		}
	}else{
		if(a[n-1]==a[0]){
			if(b[n-1]==pre){
				cout << c[n-1];
			}else{
				cout << b[n-1];
			}
		}else{
			cout << a[n-1];
		}
	}
	cout << " ";
	cout << endl;
}

int main(){
	int t;cin >> t;while(t--)solve();
}
