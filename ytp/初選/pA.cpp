#include<bits/stdc++.h>
//#define ios_base:sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int mxN = 1e3;
int n,m;
int G[mxN][mxN];
void dfs(int r,int c){
	G[r][c]='0';
	if(r-1>=0&&G[r-1][c]=='X')dfs(r-1,c);
}
int main(){
	cin >> n >> m;
	string str;
	getline(cin,str);
	for(int i = 0; i<n; i++){
		getline(cin,str);
		for(int j = 0; j<m; j++){
			G[i][j] = str[j];
		}
	}
	int cnt =0;
	for(int i = n-1; i>=0; i--){
		for(int j = 0; j<m; j++){
			if(G[i][j]=='X'){
				dfs(i,j);cnt++;
			}
		}
	}
	cout << cnt <<endl;
}
