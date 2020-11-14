#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using pii = pair<int,int>;
using ll = long long;
//#define int ll
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define vi vector<int>
constexpr ll mxN = 1e2+5;
constexpr ll MOD = 1e9+7;
/*
ll pow_mod(int n, int p){
	int rESULt = 1;
	while(p){
		if(p&1) rESULt=(rESULt * n)%MOD;
		n = (n*n)%MOD;
		p>>=1;
	}
	return rESULt;
}
*/
int G[mxN][mxN];
bool vis[mxN][mxN];
int n,m;
bool vaild(int r,int c){
	return min(r,c)>=0&&r<n&&c<m;
}
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};

bool abnormal(int r,int c){
	for(int i = 0; i<4; i++){
		int nr = r+dr[i];
		int nc = c+dc[i];
		if(vaild(nr,nc)&&G[nr][nc]==G[r][c])return 1;
	}
	return 0;
}



void dfs(int r,int c){
	if(!vis[r][c]){
		for(int i = 0; i<4; i++){
			int nr = r+dr[i];
			int nc = c+dc[i];
			if(vaild(nr,nc)&&G[nr][nc]==G[r][c]+1&&!vis[nr][nc])dfs(nr,nc);
		}
	}
	for(int i = 0; i<4; i++){
		int nr = r+dr[i];
		int nc = c+dc[i];
		if(vaild(nr,nc)&&G[nr][nc]==G[r][c])dfs(nr,nc);
	}
}

void solver(){
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> G[i][j];
			vis[i][j]=0;
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(abnormal(i,j))dfs(i,j);
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
	
}

int main(){
	int T;cin >> T;while(T--)solver();
}
