#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

constexpr int mxN = 10;
bool G[mxN][mxN];

bool vaild(int r,int c){
	if(min(r,c)<0||max(r,c)>=5)return 0;
	return 1;
}

void dfs(int r,int c){
	G[r][c]=0;
	if(vaild(r+1,c)&&G[r+1][c])dfs(r+1,c);
	if(vaild(r-1,c)&&G[r-1][c])dfs(r-1,c);
	if(vaild(r,c+1)&&G[r][c+1])dfs(r,c+1);
	if(vaild(r,c-1)&&G[r][c-1])dfs(r,c-1);
}

int main(){
	for(int i = 0; i<5; i++){
		for(int j = 0; j<5; j++){
			cin >> G[i][j];
		}
	}
	int cnt = 0;
	for(int i = 0; i<5; i++){
		for(int j = 0; j<5; j++){
			if(G[i][j]){
				dfs(i,j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	
}
