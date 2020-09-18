#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e6;
vector<int> G[mxN];	
int weight[mxN];
void pull(int n){
	if(G[n].size()==0)return;
	pull(G[n][0]);
	pull(G[n][1]);
	weight[n]=weight[G[n][0]]+weight[G[n][1]];
}

void dfs(int u,int w){
//	cout << G[u][0]<<" "<<G[u][1] <<endl;
	if(G[u].size()==0){
		weight[u]+=w;
		cout << u << " ";
		return;
	}
	if(weight[G[u][0]]<=weight[G[u][1]])dfs(G[u][0],w);
	else if(weight[G[u][0]]>weight[G[u][1]])dfs(G[u][1],w);
}

int main(){
	int n,m;
	cin >> n >> m;
	fill(weight,weight+n+1,0);
	for(int i = n; i<=2*n-1; i++){
		cin >> weight[i];
	}
	vector<int> work(m);
	for(int i = 0; i<m; i++){
		cin >> work[i];
	}
	for(int i = 0; i<n-1; i++){
		int p,l,r;
		cin >> p >> l >> r;
		G[p].emplace_back(l);
		G[p].emplace_back(r);
	}
	pull(1);
	for(int x:work){
		dfs(1,x);
		pull(1);
	}
}
