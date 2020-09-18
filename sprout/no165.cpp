#include<bits/stdc++.h>
using namespace std;
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
int main(){
	IO_OP
	int t;cin >> t;while(t--){
		vector<int> G[100005];
		int n,m;
		cin >> n >> m;
		int indegree[100005];
		fill(indegree,indegree+n,0);
		for(int i = 0; i<m; i++){
			int u,v;cin >> u >> v;
			indegree[v]++;
			G[u].emplace_back(v);
		}
		priority_queue<int,vector<int>,greater<int>> pq;
		int chk = 0;
		for(int i = 0; i<n; i++){
			if(!indegree[i]){
				pq.push(i);
				chk++;
			}
		}
		vector<int> ans;
//		cout << "OK : "<< pq.top() << endl;
		while(!pq.empty()){
			int u = pq.top();
			pq.pop();
			for(int x:G[u]){
				indegree[x]--;
				if(!indegree[x]){
					pq.push(x);
					chk++;
				}
//				cout << indegree[x] <<endl;
			}
			ans.emplace_back(u);
		}
		if(chk!=n){
			cout << "QAQ";
		}else{
			for(int i = 0; i<n; i++){
				cout << ans[i];
				if(i!=n-1)cout << " ";
			}
//			for(int x:ans)cout <<x << " ";
		}
		cout << endl;
//		for(int i = 0; i<n; i++)G[i].clear();
	}
} 
