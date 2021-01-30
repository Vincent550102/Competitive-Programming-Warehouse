#include<bits/stdc++.h>
#define _ << ' ' <<
using namespace std;
constexpr int MOD = 1e9+7;
constexpr int mxN = 1e3+5;
char G[mxN][mxN];
int dp[mxN][mxN];
int h,w;
bool vaild(int r,int c){
	return min(r,c)>=0&&r<h&&c<w;
}

int main(){
	cin >> h >> w;
	for(int i = 0; i<h; i++){
		for(int j = 0; j<w; j++){
			cin >> G[i][j];
			dp[i][j] = 0;
		}
	}
	dp[0][0]=1;
	for(int i = 0; i<h; i++){
		for(int j = 0; j<w; j++){
			if(!i&&!j||G[i][j]=='#')continue;
//			cout << i _ j _ (vaild(i-1,j)?dp[i-1][j]:0) _ (vaild(i,j-1)?dp[i][j-1]:0) << " ";
			dp[i][j] = ((vaild(i-1,j)?dp[i-1][j]:0)%MOD + (vaild(i,j-1)?dp[i][j-1]:0)%MOD)%MOD;
		}
	}
//	cout << "-----\n";
//	for(int i = 0; i<h; i++){
//		for(int j = 0; j<w; j++){
//			cout << (G[i][j]=='#'?'#':dp[i][j]) << " ";
//		}
//		cout << endl;
//	}
	cout << dp[h-1][w-1] << endl;
	
}
