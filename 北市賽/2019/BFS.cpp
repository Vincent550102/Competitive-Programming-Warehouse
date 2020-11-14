#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using pii = pair<int,int>;
//using ll = long long;
#define F first
#define S second
const int mxN = 1e4+5;
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
char G[mxN][mxN];
bool vis[mxN][mxN]={0};
int main(){
	io_op
	int n,m;
	while(cin >> n&&n){
		pii root;
		for(int i = 0; i<n; i++){
			cin >> G[i];
			m=strlen(G[i]);
			for(int j = 0; j<m; j++){
				vis[i][j]=0;
				if(G[i][j]=='K')root ={i,j};
			}
		}
		queue<pair<pii,int> > qu;
		qu.push({root,0});
		int ans = -1;
		while(!qu.empty()){
			pii now = qu.front().F;
			if(G[now.F][now.S]=='@'){
				ans = qu.front().S;
				break;	
			} 
			G[now.F][now.S]='#';
			for(int i = 0; i<4; i++){
				int nr = now.F+dr[i];
				int nc = now.S+dc[i];
				if(G[nr][nc]!='#'&&!vis[nr][nc]){
					qu.push({{nr,nc},qu.front().S+1});
					vis[nr][nc]=1;	
				}
			}
			qu.pop();
		}
		if(!(ans+1))cout << "= =\"";
		else cout << ans;
		cout << '\n';
	}
}
