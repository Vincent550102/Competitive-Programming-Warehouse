#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
signed main(){
	int t;cin >> t;while(t--){
		int n;
		cin >> n;
		int dp[100005];
		vector<int> v(n+1);
		for(int i = 1; i<=n; i++){
			cin >> v[i];
		}
		dp[1] = v[1];
		dp[2] = v[2];
		dp[3] = v[3]+v[1];
		for(int i = 4; i<=n; i++){
			dp[i] = max(dp[i-2],dp[i-3])+v[i];
		}
		cout << max(dp[n-1],dp[n]) << endl;
	}
}
