#include<bits/stdc++.h>
using namespace std;
vector<char> g_tmp;
vector<vector<char> > g;
int h,w;
int dr[4] = {0,0,1,-1}; 
int dc[4] = {1,-1,0,0};
void dfs(int r, int c){
	
	
	g[r][c] = '#';
	for(int i = 0; i<4; i++){
		if(r+dr[i]>=h||r+dr[i]<0)continue;
		if(c+dc[i]>=w||c+dc[i]<0)continue;
		if(g[r+dr[i]][c+dc[i]]=='#')continue;
//		cout << r <<" "<< c<< " " << g[r][c] << endl; 
		dfs(r+dr[i] , c+dc[i]);
	}
	
}

int main(){
	int t; cin>> t; while(t--){
		
		cin >> h >> w;
		g_tmp.resize(w);
		g.resize(h,g_tmp);
		for(int i = 0; i<h; i++){
			for(int j = 0; j<w; j++){
				cin >> g[i][j];
			}
		}
		int cnt = 0;
		for(int i = 0; i<h; i++){
			for(int j = 0; j<w; j++){
				if(g[i][j] == '.'){
					dfs(i,j);
					cnt++;
				}
				
			}
		}
		cout << cnt << endl;
		g.clear();
	}
}
