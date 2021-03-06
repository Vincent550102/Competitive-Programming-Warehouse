#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define Pb push_back
using namespace std;
const int mxN = 1e5+5;
vector<int> G[mxN];
int n,m;
int dep[mxN], fa[mxN][25];

void dfs(int u=-1, int v=0,int d=0){
	dep[v]=d;
	fa[v][0]=u;
	for(int x:G[v]){
		if(x!=u)dfs(v,x,d+1);
	}
}

void build(){
	for(int up = 1; (1<<up)<n; up++){
		for(int i = 0; i<n; i++){
			fa[i][up] = fa[fa[i][up-1]][up-1];
		}
	}
}

int lca(int a, int b){
	if(dep[b]<dep[a])swap(a,b);
	int mostdep = 1;
	while((1<<mostdep+1)<=dep[b])mostdep++;
	
	for(int up = mostdep; up>=0; up--){
		if(dep[fa[b][up]]>=dep[a]){
			b = fa[b][up];
//			cerr << b << endl;
		}
	}
	if(a==b)return a;
//	assert(dep[a]!=dep[b]);
	for(int up = mostdep; up>=0; up--){
		if(fa[a][up]!=fa[b][up]){
			a=fa[a][up];
			b=fa[b][up];
		}
	}
	return fa[a][0];
}

int main(){
	io_op
	cin >> n >> m;
	for(int i = 0; i<n-1; i++){
		int a,b;cin >> a >> b;
		G[a].Pb(b);
		G[b].Pb(a);
	}
	dfs();
	fa[0][0]=0;
	build();
	for(int i = 0; i<m; i++){
		int a,b;cin >> a >> b;
		cout << dep[a]+dep[b]-2*dep[lca(a,b)] << endl;
	}
}
