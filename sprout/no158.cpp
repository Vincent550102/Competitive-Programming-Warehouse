#include<bits/stdc++.h>
#define INF 1e9

using namespace std;
using ll = long long;
#define int ll
int c[1005],v[1005];
int dp[105][1005][105];
signed main(){
	int t;cin >> t;while(t--){
		int N,M,K;
		cin >> N >> M >> K;
		for(int i = 1; i<=N; i++){
			cin >> c[i] >> v[i];
		}
		for(int i = 0; i<105; i++){
			for(int j = 0; j<1005; j++){
				for(int k = 0; k<105; k++){
					dp[i][j][k] = -INF;
				}
			}
		}
		for(int i = 0; i<1005; i++){
			for(int j = 0; j<105; j++){
				dp[0][i][j] = 0;
			}
		}
		for(int i = 0; i<105; i++){
			for(int j = 0; j<1005; j++){
				dp[i][j][0] = 0;
			}
		}
		for(int i = 0; i<105; i++){
			for(int j = 0; j<105; j++){
				dp[i][0][j] = 0;
			}
		}
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				for(int k = 1; k<=K; k++){
					if(j-c[i]>=0)dp[i][j][k] = max(dp[i-1][j-c[i]][k-1]+v[i],dp[i-1][j][k]);
					else dp[i][j][k] = dp[i-1][j][k];
//					cout << dp[i][j][k] << " ";
				}
			}
//			cout << endl;
		}
		cout << dp[N][M][K] << endl;
	}
}
