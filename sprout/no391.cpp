#include<bits/stdc++.h>
using namespace std;
#define INF 0xffffffffffffffff
using ll = unsigned long long;
#define int ll 
int dis[10005];
int n,m,s,e,f;
vector<pair<int,int> > G[100005];
void dijkstra(int p){
	priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int> > > pq;
	fill(dis,dis+n+1,INF);
	dis[p] = 0ull;
	pq.push(make_pair(0,p));
	while(!pq.empty()){
		pair<int,int> u = pq.top();
		pq.pop();
		if(dis[u.second]!=u.first){
			continue;
		}
		for(auto e:G[u.second]){
			if(dis[e.first] > u.first+e.second){
				dis[e.first] = u.first+e.second;
				pq.push(make_pair(dis[e.first] ,e.first));
			}
		}
	}
}
int a,b,c,d,dm;
signed main(){
	int t;cin>>t;while(t--){
		
		cin >> n >> m >> s >> e >> f;
		for(int i = 1; i<=n; i++)G[i].clear();
		
		for(int i = 0; i<m; i++){
			cin >> a >> b >>c >> d >> dm;
			int weight;
			if(f>d)weight = (f-d)*dm+d*c;
			else weight = f*c;
			G[a].emplace_back(make_pair(b,weight));
		}
//		for(int i = 1; i<=n; i++){
//			cout << i << " : ";
//			for(auto x:G[i])cout <<x.first <<"¡A" << x.second << " ";
//			cout <<endl;
//		}
		dijkstra(s);
		cout << dis[e] << endl; 
	}
}
