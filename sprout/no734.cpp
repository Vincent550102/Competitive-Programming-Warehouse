#include<bits/stdc++.h>
#define EB emplace_back
#define MK make_pair
#define PII pair<int,int>
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
using ll = unsigned long long;
//#define int ll 
using namespace std;
vector<PII> G[200005];
bool is_visit[200005];

int main(){
	IO_OP
	int n,m;
	cin >> n >> m;
	for(int i = 0; i<m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		G[u].EB(MK(w,v));
		G[v].EB(MK(w,u));
	}
	
	fill(is_visit,is_visit+n+1,0);
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	for(auto x:G[1]){
		pq.push(x);
//		is_visit[x.second] = true;
	}
	
	is_visit[1] = true;
	int cnt = 1;
	ll ans = 0;
	
	while(cnt!=n){
		auto u = pq.top();
		pq.pop();
		if(is_visit[u.second])continue;
		ans+=u.first;
		for(auto x:G[u.second]){
			if(!is_visit[x.second]){
				pq.push(x);
			}
		}
		is_visit[u.second] = true;
		cnt++;
	}
	cout << ans << '\n';
}
