#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
#define endl '\n'
using ll = long long;
//#define int ll 
constexpr ll MOD = 1e9+7;
using namespace std;
constexpr int mxN = 50;
int G[mxN][mxN];
int N;
ll cnt = 0;
constexpr int dr[]={1,0,-1,0};
constexpr int dc[]={0,1,0,-1};
bool vaild(int r,int c){
	if(r>=0&&c>=0&&r<N&&c<N)return 1;
	return 0;
}

void dfs(int r,int c){
	if(G[r][c]==N*N){
		cnt++;
		cnt=cnt%MOD;
		return;
	}
	for(int i = 0; i<4; i++){
		int nr=r+dr[i];
		int nc=c+dc[i];
		if(vaild(nr,nc)&&G[nr][nc]>G[r][c])dfs(nr,nc);
	}
}

signed main(){
	io_op
	cin>> N;
	pii start;
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			cin >> G[i][j];
			if(G[i][j]==1){
				start.F=i;
				start.S=j;
			}
		}
	}
	dfs(start.F,start.S);
	cout << cnt%MOD << endl;
}
