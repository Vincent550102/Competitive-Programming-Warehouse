#include<bits/stdc++.h>
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int ans = 0;

vector<int> child_tmp;
vector<vector<int> > MP;
vector<int> dp;
void dfs(int node){
	if(dp[node]!=1){
		ans+=dp[node];
		return;
	}
	ans++;
	int a = ans;
	if(MP[node].empty())return;
	else for(auto x:MP[node])dfs(x);
	dp[node]=ans-a+1;
}

int main(){
	IO_OP
	int t;cin >> t; while(t--){
		int n,m;
		cin >> n >> m;
		MP.resize(n+1,child_tmp);
		while(m--){
			int x,y;cin >> x >> y;
			MP[x].emplace_back(y);
		}
		dp.resize(n+1,1);
		int q;cin >> q;while(q--){
			int f;cin >> f;
			ans = 0;
			dfs(f);
			cout << ans << endl;
		}
		MP.clear();
		child_tmp.clear();
		
//		for(auto x:dp)cout << x << " ";
		dp.clear();
	}
}

