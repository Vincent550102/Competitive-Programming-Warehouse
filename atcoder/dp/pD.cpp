#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e2+5;
const int mxM = 1e5+5;
long long dp[mxN][mxM];
long long n,w,wei[mxN],val[mxN];
int main(){
	cin >> n >> w;
	for(int i = 1; i<=n; i++){
		cin >> wei[i] >> val[i];
	}
	for(int i = 0; i<=n; i++){
		for(int j = 0;j<=w; j++){
			dp[i][j] = 0;
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1;j<=w; j++){
			if(j-wei[i]>=0&&i-1>=0) dp[i][j] = max(dp[i-1][j],dp[i-1][j-wei[i]]+val[i]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	long long ans = 0;
//	for(int i =1; i<=n; i++){
//		for(int j = 1; j<=w; j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	for(int i = 0; i<=n; i++){
		ans = max(ans,dp[i][w]);
	}
	cout << ans << endl;
}
