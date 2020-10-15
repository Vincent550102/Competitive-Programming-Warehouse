#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
const int mxN = 1e5+5;
const int inf = 1e4+5;
int dp[mxN];
int main(){
	io_op
	int n;
	cin >> n;
	fill(dp,dp+n,inf);
	vector<int> v(n);
//	dp[i] = min(dp[i-1],dp[i-2],dp[i-3])+v[i]
	for(int &x:v)cin >> x;
	dp[0] = v[0];
	dp[1] = v[1];
	dp[2] = min(dp[1],dp[0])+v[2];
	for(int i = 3; i<n; i++){
		dp[i] = min({dp[i-1],dp[i-2],dp[i-3]})+v[i];
	}
	cout << min(dp[n-1],dp[n-2]) << endl;
}
