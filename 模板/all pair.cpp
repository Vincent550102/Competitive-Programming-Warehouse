#include<bits/stdc++.h>
using namespace std;
constexpr int inf = 1e7;
constexpr int mxN = 1e2+5;
int adj_G[mxN][mxN];

int main(){
	int n;
	cin >> n;
	
	for(int i = 0; i <=n; i++){
		for(int j = 0; j<=n; j++){
			adj_G[i][j]=inf;
			if(i==j)adj_G[i][j]=0;
		}
	}
	
	for(int i = 0; i<n; i++){
		int a,b,w;cin >> a >> b >> w;
		adj_G[a][b]=w;
		adj_G[b][a]=w;
	}
	
	for(int k = 0; k<=n; k++){
		for(int i = 0; i<=n; i++){
			for(int j = 0; j<=n; j++){
				adj_G[i][j]=min(adj_G[i][j],adj_G[i][k]+adj_G[k][j]);
			}
		}
	}
	
	for(int i = 0; i<=n; i++){
		for(int j = 0; j<=n; j++){
			cout << adj_G[i][j] << " ";
		}
		cout << endl;
	}
	
}
