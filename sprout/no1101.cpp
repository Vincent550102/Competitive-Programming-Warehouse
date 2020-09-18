#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second

int n,m;
vector<int> g_tmp;
vector<vector<int> > g;
vector<bool >color;
bool flag = true;
vector<bool> visited;
void dfs1(int r,int c){ // r->now v->parent
    color[r] = c;
    for(auto x:g[r]){
        if(!visited[x]){
            visited[x] = true;
            if(c==0)dfs1(x,1);
            else dfs1(x,0);
        }
    }
}

void dfs2(int r,int c){
    //cout << r << endl;
    visited[r] = true;
    for(auto x:g[r]){
        //cout << x << endl;
        if(c==0){
            if(color[x]==0)flag = false;
        }else{
            if(color[x]==1)flag = false;
        }
        if(!visited[x]){
            if(c==0)dfs2(x,1);
            else dfs2(x,0);
        }
    }
}

int main(){
	while(cin >> n&&n){
		cin >> m;
		g.resize(n,g_tmp);
		for(int i = 0; i<m; i++){
			int a,b;
			cin >> a >> b;
			g[a].emplace_back(b);
			g[b].emplace_back(a);
		}
		int root = 0;
		flag = true;
		visited.resize(n,false);
		color.resize(n,0);
		dfs1(0,0);
		visited.clear();
		visited.resize(n,false);
		dfs2(0,0);
		if(flag)cout << "NORMAL.";
		else cout << "RAINBOW.";
		cout << endl;
		g.clear();
		visited.clear();
	}
}
