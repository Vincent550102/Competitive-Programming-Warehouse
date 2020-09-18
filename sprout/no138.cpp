#include<bits/stdc++.h>
using namespace std;
#define mod 1000007
using ll = long long;
#define int ll
signed main(){
	int t;
	cin >> t;
	int dp[100005];
	dp[1] = 0;
	dp[2] = 3;
	dp[4] = 11;
	for(int i = 6; i<100004; i++){
		dp[i] = (4*dp[i-2] -dp[i-4] +mod)%mod;
	}
	while(t--){
		int n;
		cin >> n;
		if(!(n%2)){
			cout << dp[n] << endl;
		}else cout << 0 << endl;
	}
}
