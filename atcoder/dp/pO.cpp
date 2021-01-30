#include<bits/stdc++.h>
using namespace std;
constexpr int mxN = 25;
constexpr int MOD= 1e9+7;
int G[mxN][mxN];
int main(){
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >> G[i][j];
			if(i>j&&G[i][j])cnt++;
		}
	}
	cout << cnt << endl;	
	cout << (cnt*(cnt-1))%MOD/2 << endl;
}
