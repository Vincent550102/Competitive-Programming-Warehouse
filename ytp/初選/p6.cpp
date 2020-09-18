#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int mxN = 1e2;
char G[mxN][mxN];

int n,m;
string ans="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

void dfs(int r,int c,string str){
	
	if(r>=n||c>=m){
		if(ans>str&&str.size()==n+m)ans=str;
//		cout << str;
//		ans = min(ans,str);	
	}else{
		dfs(r,c+1,str+G[r][c+1]);
		dfs(r+1,c,str+G[r+1][c]);
	}
	
}

int main(){
	io_op
	cin >> n >> m;
	
	for(int i = 0; i<n; i++){
		string str;
		cin >> str;
		for(int j = 0; j<m; j++){
			G[i][j] = str[j];
		}
	}
	string s;
	s+=G[0][0];
	dfs(0,0,s);
	cout << ans << endl;
}
