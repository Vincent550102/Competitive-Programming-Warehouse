#include<bits/stdc++.h>
using namespace std;
#define MK make_pair
#define MAXN 1e5
#define EB emplace_back
#define INF 1e18
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
#define int ll
vector<pair<int,int> > G[200005];
vector<pair<int,int> > rG[200005];
int n,m,q;
int dis1[200005];
int dis2[200005];
void dijkstra1(int s){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > > pq;
	fill(dis1,dis1+n+1,INF);
	dis1[s] = 0;
	pq.push(MK(0,s));
	while(!pq.empty()){
		pair<int,int> u = pq.top();
		pq.pop();
		if(dis1[u.second]!=u.first){
			continue;
		}
		for(auto x:G[u.second]){
			if(dis1[x.second]>u.first+x.first){
				dis1[x.second] = u.first+x.first;
				pq.push(MK(dis1[x.second],x.second));
			}
		}
	}
}
void dijkstra2(int s){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > > pq;
	fill(dis2,dis2+n+1,INF);
	dis2[s] = 0;
	pq.push(MK(0,s));
	while(!pq.empty()){
		pair<int,int> u = pq.top();
		pq.pop();
		if(dis2[u.second]!=u.first){
			continue;
		}
		for(auto x:rG[u.second]){
			if(dis2[x.second]>u.first+x.first){
				dis2[x.second] = u.first+x.first;
				pq.push(MK(dis2[x.second],x.second));
			}
		}
	}
}
signed main(){
	IO_OP
	cin >> n >> m >> q;
	for(int i = 0; i<m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		G[u].EB(MK(w,v));
		rG[v].EB(MK(w,u));
	}
	dijkstra2(n);
	dijkstra1(1);
	while(q--){
		int u,v;
		cin >> u >> v;
		cout << min(dis1[u]+dis2[v]+1,dis1[n]) << endl;
	}
} 
