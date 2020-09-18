#include<bits/stdc++.h>
using namespace std;
const int INF = -1e9;
int c[105],v[105];
int dp[105][1000005];
int main(){
	int t;cin >> t;while(t--){
		int n,m;
		cin >> n >> m;
		
		for(int i = 1; i<=n; i++){
			cin >> c[i] >> v[i];
		}
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				dp[i][j] = INF;
			}
		}
		for(int i = 0; i<m; i++){
			dp[0][i] = 0;
		}
		for(int i = 1; i<=n; i++){
			for(int j = 0; j<=m; j++){
				if(c[i]<=j)dp[i][j] = max(dp[i-1][j] , dp[i-1][j-c[i]]+v[i]);
				else dp[i][j] = dp[i-1][j];
			}
		}
		for(int i = 1; i<=n; i++){
			for(int j = 0; j<=m; j++){
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		cout <<dp[n][m];
	}
}
