#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>node_tmp;
vector<vector<int> > node;
vector<int> dp,s;

void dfs(int u,int p){
	s[u] = 1;
	for(auto x:node[u]){
		if(x==p)continue;
		dfs(x,u);
		dp[u] = max(dp[u],s[x]);
		s[u] += s[x];
	}
	dp[u] = max(dp[u],n-s[u]);
}

int main(){
	int t;cin >> t;while(t--){
		cin >> n;
//		node.clear();
		node.resize(n,node_tmp);
		dp.resize(n,0);
		s.resize(n,0);
		
		int p,c;
		for(int i = 0; i<n-1; i++){
			cin >> p >> c;
			node[p].emplace_back(c);
			node[c].emplace_back(p);
		}
		dfs(0,-1);
		int a = 1e9;
		int ans = -1;
		for(int i = n-1; i>=0; i--){
			if(dp[i]<=a){
				a = dp[i];
				ans = i;
			}
		}
		cout << ans << endl;
		node.clear();
		dp.clear();
		s.clear();
				
	}
}
