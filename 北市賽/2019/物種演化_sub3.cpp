#include<bits/stdc++.h>
#include<unordered_map> 

using namespace std;
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using pii = pair<int,int>;
#define F first
#define S second
const int mxN = 1e5+5;
const int INF = 1e5+5;
int n,m;
int Dep[mxN]={0};
int P[mxN];
vector<int> G[mxN];

void dfs(int u,int v){
	P[v]=u;
	int max_dep = 0;
	Dep[v] = (u==-1)?0:Dep[u]+1;
	for(int x:G[v]){
		if(x!=u)dfs(v,x);
	}
}

int LCA(int a,int b){
	while(Dep[a]>Dep[b])a=P[a];
	while(Dep[a]<Dep[b])b=P[b];
	while(a!=b){
		a = P[a];
		b = P[b];
	}
	return a;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

int main(){//700000
	io_op
	cin >> n >> m;
	for(int i = 0; i<n-1; i++){
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(-1,0);
	unordered_map<pii,int,pair_hash> save;
	for(int i =0; i<m; i++){
		int a,b;
		cin >> a >> b;
		if(a<b)swap(a,b);
		if(save.count({a,b}))cout << save[{a,b}];
		else{
			int ans = Dep[a]+Dep[b]-2*Dep[LCA(a,b)];
//			cout << LCA(a,b) << endl;
			save[{a,b}]=ans;
			cout << ans;
		}
//		for(int i = 0; i<n; i++)cout << dis[i] << " ";cout << '\n';
		cout << '\n';
	}
//	for(int i = 0; i<n; i++){
//		cerr << i<<" : "<<Dep[i] << " ";
//	}
}
