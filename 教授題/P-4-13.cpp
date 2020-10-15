#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxN = 1e5+5;
#define int ll 
int arr[mxN];
int dp[mxN];
signed main(){
	int n;
	cin >> n;
	fill(dp,dp+n,0);
	//dp[i] = dp[i-1] + arr[i] if dp[i-1]>0 else arr[i]
	for(int i = 0; i<n ;i++){
		cin >> arr[i];
	}
	
	dp[0] = arr[0];
	int ans = 0;
	for(int i = 1; i<n; i++){
		if(dp[i-1]>0)dp[i] = dp[i-1] + arr[i];
		else dp[i] = arr[i];
		ans = max(ans,dp[i]);
	}
	cout << ans << endl;
}

