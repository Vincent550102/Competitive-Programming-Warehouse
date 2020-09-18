#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
int main(){
	FAST
	int t;cin >> t;while(t--){
		int N,M;
		cin >> N >> M;
		vector<int> v(N);
		for(int i = 0; i<N; i++)cin >> v[i];
//		dp[i][0] -> 不拿
//		dp[i][1] -> 拿原樣
//		dp[i][2] -> 拿乘以2
//		dp[i][0] = max(dp[i-1][0],dp[i-1][1],dp[i-1][2]);
//		dp[i][1] = 
		int dp[100005];
		for(int i = 0; i<N; i++){
			if(v[i]*2<v[i-1]){
				for(int j = 0; j<3; j++){ 
					dp[i][0] = max(dp[i][0],dp[i-1][j]);
				} 
			}else if(v[i]>=v[i-1]){
				dp[i][1] = dp[i-1][1]+1;
			}else if(v[i]*2>=v[i]*2)
			
		} 
	}
}
