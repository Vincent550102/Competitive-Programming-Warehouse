#include<bits/stdc++.h>
using namespace std;
int ans[100];
int num[100];
int k;

void dfs(int idx,int n){
	if(n==6){
		for(int i = 0; i<6; i++)if(i!=5)cout << ans[i] << " ";else cout<<ans[i]; 
		cout << endl;
	}else{
		if(idx>=k)return;
		ans[n]=num[idx];
		dfs(idx+1,n+1);
		dfs(idx+1,n);
	}
}
int main(){
	bool is_start = true;
	while(cin >> k&&k){
		if(!is_start){
			cout << endl;
		}else{
			is_start = false;
		}
		for(int i = 0; i<k; i++)cin >> num[i];
		dfs(0,0);
	}
}

