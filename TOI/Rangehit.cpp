#include<bits/stdc++.h>
using namespace std;

int main(){
	map<int,int> MP;
	int n;cin >> n;
	for(int i = 0; i<n; i++){
		int l,r,w;cin >> l >> r >> w;
		MP[l]+=w;
		MP[r]-=w;
	}
	int ans = -1, cur = 0;
	for(auto p:MP){
		cur+=p.second;
		ans = max(ans,cur);
		cout << cur << endl;
	}
	cout << ans << endl;
}
