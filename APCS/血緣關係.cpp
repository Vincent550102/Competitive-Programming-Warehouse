#include<bits/stdc++.h>
#define F first
#define S second
#define pii pair<int,int>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int mxN = 1e6;
vector<int> G[mxN];
vector<pii> relate;

void dfs(int u){
	if(G[u].empty())return;
	for(int x:G[u]){
		dfs(x);
		if(relate[x].F+1>=relate[u].F){
			swap(relate[u].F,relate[u].S);
			relate[u].F=relate[x].F+1;
		}else if(relate[x].F+1>relate[u].S){
			relate[u].S=relate[x].F+1;
		}
	}
}

int main(){
	io_op
	int n;
	while(cin >> n){
		
		bool is_root[mxN];
		fill(is_root,is_root+n,1);
		for(int i = 0; i<n-1; i++){
			int p,c;
			cin >> p >> c;
			G[p].push_back(c);
			is_root[c]=0;
		}
		int root = -1;
		for(int i = 0; i<n; i++){
			if(is_root[i])root=i;
		}
		relate.resize(n,{0,-1});
		dfs(root);
		int ans = 0;
		for(auto x:relate){
	//		cout << x.F << " " << x.S << endl;
			ans = max(ans,((x.S+1)?x.F+x.S:0));
		}
		cout << ans << endl;
		relate.clear();
		for(int i = 0; i<n; i++){
			G[i].clear();
		}
	}
}
