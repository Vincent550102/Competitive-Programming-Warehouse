#include<bits/stdc++.h>
#define F first
#define S second
#define All(v) v.begin(),v.end()
#define Eb emplace_back
using namespace std;
constexpr int mxN = 1e5;
constexpr int inf = 1e7;
int n;
using pii = pair<int,int>;
vector<pii> G[mxN];

int dis[mxN];

void dijkstra(int v = 0){
	for(int i = 0; i<=n; i++){
		dis[i]=inf;
	}
	dis[v]=0;
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.push({0,v});
	while(!pq.empty()){
		pii u =pq.top();pq.pop();
		if(dis[u.S]!=u.F){
			continue;
		}
		for(pii x:G[u.S]){
			if(dis[x.S]>dis[u.S]+u.F){
				dis[x.S]=dis[u.S]+x.F;
				pq.push({dis[x.S],x.S});
			}
		}
	}
}

int main(){
	cin >> n;
	for(int i = 0; i<n; i++){
		int a,b,w;
		cin >> a >> b >> w;
		G[a].push_back({w,b});
		G[b].push_back({w,a});
	}
	dijkstra(1);
	for(int i =1; i<=n; i++){
		cout << dis[i] << " ";
	}
}
