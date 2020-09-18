#include<bits/stdc++.h>
using namespace std;
int c[105],v[105];
int dp[105][10005]; 
const int INF = 1e9;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
int main(){
	FAST
	int t;cin>> t;while(t--){
		int n,m;
		cin >> n >> m;
		int v_sum = 0;
		for(int i = 1; i<=n; i++){
			cin >> c[i]>> v[i];
			v_sum+=v[i];
		}
		for(int i = 0; i<=v_sum; i++){
			for(int j = 0; j<=n; j++){
				dp[j][i] = INF;
			}
		}
		for(int i = 0; i<=n; i++){
			dp[i][0] = 0;
		}
		for(int i = 1; i<=n; i++){
			for(int j = 0; j<=v_sum; j++){
				if(v[i]<=j)dp[i][j] = min(dp[i-1][j],dp[i-1][j-v[i]]+c[i]);
				else dp[i][j] = dp[i-1][j];
			}
		}
		int max_ans = -INF;
		for(int i = 1; i<=n; i++){
			for(int j = 0; j<=v_sum; j++){
				if(dp[i][j]<=m){
					max_ans = max(max_ans,j);
				}
			}
		}
		
		cout << max_ans << endl;
	}
}
