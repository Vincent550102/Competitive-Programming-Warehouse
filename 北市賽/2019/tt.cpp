#include<bits/stdc++.h>
using namespace std;
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using pii = pair<int,int>
#define F first
#define S second
constexpr int mxN = 1e5;
constexpr int INF = 1e7;
int dis[mxN];
vector<pii> G[mxN];
int n;

void dijkstra(int p){
	priority_queue<pii,vector<pii>,greater<pii> > pq{};
	fill(dis,dis+n,INF);
	dis[p]=0;
	pq.push({0,p});
	while(!pq.empty()){
		pii u = pq.top();pq.pop();
		if(u.F!=dis[u.S]){
			continue;
		}
		for(pii x:G[u.S]){
			if(dis[x.S]>x.F+dis[u.S]){
				dis[x.S]=x.F+dis[u.S];
				pq.push({dis[u.S],u.S});
			}
		}
	}
}

int main(){
	
}
