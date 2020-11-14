#include<bits/stdc++.h>
using namespace std;
const int mxN=1e3+3,mxM=1e3+3;
char G[mxN][mxM];
int n,m;
int dr[8] = {1,1,-1,0,0,-1,-1,1};
int dc[8] = {-1,0,1,-1,1,-1,0,1};
int watch(int r,int c){
	int cnt = 0;
	for(int i = 0; i<8; i++){
		int nr = r+dr[i];
		int nc = c+dc[i];
		if(nr>=0&&nc>=0&&nr<=n-1&&nc<=m-1){
			if(G[nr][nc]=='*')cnt++;
//			cout << nr << " " << nc << endl;
		}
	}
	return cnt;
}

int main(){
	int c = 0;
	while(cin >> n >> m&&(n||m)){
		c++;
		if(c!=1)cout << endl;
		for(int i = 0;i<n; i++){
			for(int j = 0; j<m; j++){
				cin >> G[i][j];
			}
		}
		for(int i = 0;i<n; i++){
			for(int j = 0; j<m; j++){
				if(G[i][j]=='.')G[i][j]=(char)'0'+watch(i,j);
			}
		}
		cout << "Field #" <<c <<":"<< endl;
		for(int i = 0;i<n; i++){
			for(int j = 0; j<m; j++){
				cout << G[i][j];
			}
			cout << endl;
		}
	}
	
	
	
}
