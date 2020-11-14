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
int dis[mxN];
vector<pii> G[mxN];
void dijkstra(int p){
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	fill(dis,dis+n,INF);
	dis[p]=0;
	pq.push({0,p});
	while(!pq.empty()){
		pii u = pq.top();pq.pop();
		if(u.F!=dis[u.S]){
			continue;
		}
		for(pii x:G[u.S]){//exter x comp u O->u->x
			if(dis[x.S]>dis[u.S]+x.F){
				dis[x.S]=dis[u.S]+x.F;
				pq.push({dis[x.S],x.S});
			}
		}
	}
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
		G[a].push_back({1,b});
		G[b].push_back({1,a});
	}
	unordered_map<pii,int,pair_hash> save;
	for(int i =0; i<m; i++){
		int a,b;
		cin >> a >> b;
		if(a>b)swap(a,b);
		if(save.count({a,b}))cout << save[{a,b}];
		else{
			dijkstra(a);
			save[{a,b}]=dis[b];
			cout << dis[b];
		}
//		for(int i = 0; i<n; i++)cout << dis[i] << " ";cout << '\n';
		cout << '\n';
	}
}
