#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
constexpr int mxN = 25;
constexpr int mxNN = 900;
constexpr int INF = 1e7;
int N;
int G[mxNN];
int dis[mxNN][mxNN] = {};
int Hash(int r,int c){
	return r*N+c;
}
int main(){
	io_op
	cin >> N;
	for(int i = 0; i<N*N; i++){
		for(int j = 0; j<N*N; j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=INF;
		}
	}
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			cin >> G[Hash(i,j)];
			if(i!=0){
				dis[Hash(i,j)][Hash(i-1,j)] = G[Hash(i-1,j)];
				dis[Hash(i-1,j)][Hash(i,j)] = G[Hash(i,j)];
			}
			if(j!=0){
				dis[Hash(i,j)][Hash(i,j-1)] = G[Hash(i,j-1)];
				dis[Hash(i,j-1)][Hash(i,j)] = G[Hash(i,j)];
			}
		}
	}
	
	for(int k = 0; k<N*N; k++){
		for(int i = 0; i<N*N; i++){
			for(int j = 0; j<N*N; j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	int Q;cin >> Q;
	while(Q--){
		int sr,sc;
		int er,ec;
		cin >> sr >> sc >> er >> ec;
		sr--;sc--;er--;ec--;
		int ans = INF;
		for(int i = 0; i<N*N; i++){
			ans = min(ans,G[Hash(sr,sc)]+dis[Hash(sr,sc)][i]+dis[i][Hash(er,ec)]-G[i]);
		}
		cout << ans << endl;
	}
	
}
