#include<bits/stdc++.h>
#include<unordered_map> 

using namespace std;
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using pii = pair<int,int>;
#define F first
#define S second
constexpr int mxN = 1e2+5;
int v[mxN][mxN];
int dp[mxN][mxN][2];
int m,n;
										////////////////////
										/**//**//**//**//**/
										/**//**//**//**//**/	
										/////**/  /**//////
											/**/  /**/
											/**/  /**/
										    /**/  /**/
									   /**//**/    /**//**/
									  /**//**/  	/**//**/
int main(){/*//700000*/
	io_op

	//dp[i][j][01][01] -> people 0or1 in (i,j) max treasure getao
	//dp[i][j][1][0] = max(dp[i-1][j][1],dp[i][j-1][1])+1 if v[i][j]==1
	//dp[i][j][0][0] = max(dp[i-1][j][0],dp[i][j-1][0])+1 if v[i][j]==1
	//dp[i][j][1][1] = max(dp[i-1][j][1],dp[i][j-1][1]) if v[i][j]==0
	//dp[i][j][0][1] = max(dp[i-1][j][0],dp[i][j-1][0]) if v[i][j]==0
	cin >> m >> n;
	for(int i = 0; i<m; i++){
		for(int j = 0; j<n; j++){
			cin >> v[i][j];
		}
	}
}
