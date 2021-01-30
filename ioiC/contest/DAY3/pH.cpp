#include<bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e5;
constexpr int inf = 1e9+7;
int dp[mxN][2];

//dp[i][0] -> normal last student
//dp[i][1] -> small last student

//dp[i][0] = dp[i-k][0]+v[i]-v[i-k+1]
//dp[i][1] = dp[i-remain][0]+v[i]-v[i-remain+1]

int main(){
	int n,k;cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i];
	}
	int remain = n%k;
	for(int k = 0; k<2; k++){
		for(int i = 0; i<n; i++){
			dp[i][k] = 0;
		}
	}
	
	dp[k-1][0] = v[k-1]-v[0];
	if(remain)dp[remain-1][1] = v[remain-1]-v[0];
	
	for(int i = k; i<n; i++) {
		dp[i][0] = dp[i-k][0]+v[i]-v[i-k+1];
		if(remain)dp[i][1] = dp[i-remain][0]+v[i]-v[i-remain+1];
	}
	
	for(int k = 0; k<2; k++) {
		for(int i = 0; i<n; i++) {
			cout << dp[i][k] << " ";
		}
		cout << endl;
	}
	cout << (remain?dp[n-1][1]:dp[n-1][0]) << endl;
	
}
