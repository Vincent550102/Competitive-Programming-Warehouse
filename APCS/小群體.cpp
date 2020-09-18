#include<bits/stdc++.h>
using namespace std;
int n;
int v[50005],visit[50005];
void dfs(int u){
	if(!visit[u]){
		visit[u]=1;
		dfs(v[u]);
	}
}

int main(){
	while(cin >> n){
		fill(visit,visit+n,0);
		for(int i = 0; i<n; i++){
			cin >> v[i];
		}
		int cnt = 0;
		for(int i = 0; i<n; i++){
			if(!visit[i]){
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << endl;
	}
} 
