#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5+5;
int dp[mxN];
int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	//dp[i] = max(dp[i-2],dp[i-3])+v[i];
	for(int &x:v)cin >> x;
	dp[0] = v[0];
	dp[1] = v[1];
	int ans = 0;
	for(int i = 2; i<n; i++){
		dp[i] = max(dp[i-2],dp[i-3])+v[i];
		ans = max(ans,dp[i]);
	}
	cout << ans << endl;
	
	
}
