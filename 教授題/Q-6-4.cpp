#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5;
int v[mxN][2];
int dp[mxN][2];
int main(){
	//dp[i][0] = min(dp[i-1][1]+abs(v[i][0]-v[i-1][1]),dp[i-1][0]+abs([i][0]-v[i-1][0]))
	//dp[i][1] = min(dp[i-1][1]+abs(v[i][1]-v[i-1][1]),dp[i-1][0]+abs([i][1]-v[i-1][0]))
	int n,l;
	cin >> n >> l;
	for(int i = 0; i<n; i++){
		cin >> v[i][0] >> v[i][1];
	}
	dp[0][0] = abs(v[0][0]-l);
	dp[0][1] = abs(v[0][1]-l);
	for(int i = 1; i<n; i++){
		dp[i][0] = min(dp[i-1][1]+abs(v[i][0]-v[i-1][1]),dp[i-1][0]+abs(v[i][0]-v[i-1][0]));
		dp[i][1] = min(dp[i-1][1]+abs(v[i][1]-v[i-1][1]),dp[i-1][0]+abs(v[i][1]-v[i-1][0]));
	}
	cout << min(dp[n-1][0],dp[n-1][1]) <<endl;
}
