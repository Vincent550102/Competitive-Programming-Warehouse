#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e2;
int wei[mxN];
int val[mxN];
int dp[mxN][mxN];
int main(){
	//dp[i][w]=max(dp[i-1][w-wei]+val,dp[i-1][w]);
	int n,w;
	cin >> n >> w;
	for(int i = 1; i<=n; i++){
		cin >> wei[i];
	}
	for(int i = 1; i<=n; i++){
		cin >> val[i];
	}
	for(int i = 1; i<=n; i++){
		dp[i][0]=0;
	}
	for(int i = 0; i<=w; i++){
		dp[0][i]=0;
	}
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<=w; j++){
			if(j>=wei[i])dp[i][j]=max(dp[i-1][j-wei[i]]+val[i],dp[i-1][j]);
			else dp[i][j]=dp[i-1][j];
		}
	}
	cout << dp[n][w];
}
