#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5;
vector<int> G[mxN];
int n,m;
int dep[mxN], fa[mxN][25];
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void dfs(int u, int par){
	for(int v : G[u]){
		if(v==par) continue;
		dep[v] = dep[u]+1;
 		fa[v][0] = u;
		dfs(v,u);
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x,y);
	int diff = dep[x]-dep[y];
	for(int i = 20;~i;i--){
		if((1<<i)&diff){
			x = fa[x][i];
		}
	}
	if(x==y){
		return x;
	}
	for(int i = 20;~i;i--){
		if(fa[x][i]!=fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	x = fa[x][0];
	return x;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ (h2 << 1);  
    }
};

int main(){
	io_op
    cin >> n >> m;
    for(int i = 0; i<n-1; i++){
        int a,b;cin >> a >> b;
        a++;b++;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    dfs(0,0);
    for(int i = 1;i <= 20;i++){
		for(int j = 1;j <= n;j++){
			fa[j][i] = fa[fa[j][i-1]][i-1];
		}
	}
    fa[0][0]=0;
    unordered_map<pair<int,int>,int,pair_hash> MP;
    for(int i = 0; i<m; i++){
        int a,b;
        cin >> a >> b;
        if(MP.count({a,b}))cout << MP[{a,b}];
        else{
            int ans = dep[a]+dep[b]-2*dep[lca(a,b)];
            MP[{a,b}]=ans;
            cout << ans;
        }
        cout << endl;
    }
} 
