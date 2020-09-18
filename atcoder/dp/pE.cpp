#include<bits/stdc++.h>
using namespace std;
long long c[105],v[105];
long long dp[105][100005];
#define inf 1e9+5
int main(){
	long long n,w;
	cin >> n >> w;
	long long v_sum = 0;
	for(int i = 1; i<=n; i++){
		cin >> c[i] >> v[i];
		v_sum+=v[i];
	}
	for(int i = 0; i<=n; i++){
		for(int j = 0;j<=v_sum; j++){
			dp[i][j]=inf;
		}
	}
//	for(int i = 0; i<=1004s
	for(int i = 0; i<=n; i++){
		dp[i][0]=0;
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=v_sum; j++){
			if(i-1>=0&&j-v[i]>=0)dp[i][j]=min(dp[i-1][j],dp[i-1][j-v[i]]+c[i]);
			else dp[i][j]=dp[i-1][j];
		}
	}
	long long ans = 0;
	
	for(long long i = 1; i<=n; i++){
		for(long long j = 0;j<=v_sum; j++){
//			cout << dp[i][j] << " ";
			if(dp[i][j]<=w){
				ans = max(j,ans);
			}
		}
//		cout << endl;
	}
	cout << ans << endl;
}
