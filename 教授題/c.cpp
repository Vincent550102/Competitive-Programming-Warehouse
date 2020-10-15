#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll 
signed main(){
	int n;
	int dp[10000];
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 3; i<=n; i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	for(int i = 1; i<=n; i++){
		cout <<dp[i] <<" ";
	}
	cout << endl;
} 
