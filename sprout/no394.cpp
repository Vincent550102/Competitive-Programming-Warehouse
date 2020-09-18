#include<bits/stdc++.h>
#define MAX_N 500
#define EB emplace_back
#define MK make_pair
#define F first
#define S second
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int n;
int adj[MAX_N+5][MAX_N+5],dis[MAX_N+5][MAX_N+5];
const int INF = 1e9+5;
int main(){
	IO_OP
	cin >> n;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin >> adj[i][j];
			if(adj[i][j]==-1) adj[i][j] = INF;
			dis[i][j] = adj[i][j];
		}
	}
	for(int h = n; h>=1; h--){
		for(int k = n-h+1; k<=; k++){//1 1 
			for(int i = n-h+1; i<=n-3; i++){
				for(int j = n-h+1; j<=n-3; j++){
					dis[i][j] = min(dis[i][k]+dis[k][j],dis[i][j]);
				}
			}
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cout << dis[i][j]<<" ";
		}
		cout << '\n';
	}
	
}
