#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define Pb push_back
#define F first 
#define S second
using namespace std;
using ll = long long;
#define int ll
using pii = pair<int,int>;
const int mxM = 1e5, inf = INT_MAX;
#define endl '\n'
int M,N,cnt = 0;
int dis[mxM];
vector<pii> G1[mxM], G2[mxM];
bitset<mxM> vis;
priority_queue<pii, vector<pii>, greater<pii> > pq;

void dijkstra1(int x = 1){
	fill(dis,dis+mxM,inf);
	dis[x]=0;
	pq.push({0,x});
	while(!pq.empty()){
		pii u = pq.top();pq.pop();
		if(u.F != dis[u.S]) continue;
		for(pii v:G1[u.S]){
			if(dis[u.S]+v.F<dis[v.S]){
				dis[v.S] = dis[u.S]+v.F;	
				pq.push({dis[v.S],v.S});
			}
		}
	}
}

void dijkstra2(int x = 1){
	fill(dis,dis+mxM,inf);	
	dis[x]=0;
	pq.push({0,x});
	while(!pq.empty()){
		pii u = pq.top();pq.pop();
		if(u.F != dis[u.S]) continue;
		for(pii v:G2[u.S]){
			if(dis[u.S]+v.F<dis[v.S]){
				dis[v.S] = dis[u.S]+v.F;
				pq.push({dis[v.S],v.S});
			}
		}
	}
}

signed main(){
	io_op
	cin >> M >> N;
	vis.reset();
	for(int i = 0; i<N; i++){
		int q,p,r;cin >> p >> q >> r;
		G1[p].Pb({r,q});
		G2[q].Pb({r,p});
		cnt+=!vis[q];
		vis[q]=1;
	}
	
	ll ans = 0;
	dijkstra1();
	if(cnt==M) for(int i = 2; i<=M; i++){
		ans += dis[i];
	}
	dijkstra2();
	if(cnt==M) for(int i = 2; i<=M; i++){
		ans += dis[i];
	}
	
	cout << (cnt==M?ans:0) << endl;
}
