#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e2;
int v[mxN];
int dp[mxN][mxN];
int main(){
	//dp[i][w]=max(dp[i-1][w-v[i]]+v[i],dp[i-1][w]);
	int n,M,S;
	cin >> n >> M >> S;
	int load=0;
	for(int i = 1; i<=n; i++){
		cin >> v[i];
		load += v[i];
	}
	int hor = load+S-M;      
	sort(v,v+n);             
	for(int i = 0; i<=hor; i++){
		dp[0][i]=0;          
	}                        
	for(int i = 1; i<=n; i++){
		dp[i][0]=0;          
	}                        
	for(int i= 1; i<=n; i++){
		for(int j = 0;j<=hor; j++){
			if(j>=v[i])
				dp[i][j]=max(dp[i-1][j-v[i]]+v[i],dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
		}	
	}
	for(int i= 1; i<=n; i++){
		for(int j = 0;j<=hor; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	int ans = 2e5+5;
	for(int i = 1; i<=n; i++){
		if(dp[i][hor]==hor){
			ans = hor;
			break;
		}
		ans = min(dp[i][hor]+v[i],ans);
	}
	cout << ans << endl;
	
}
