#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
#define int ll

signed main(){
	FAST
	int t;cin >> t; while(t--){
		int n;cin >> n;
		int ans = 1;
		bool ok = false;
		int pre_n;
		cin >> pre_n;
		for(int i = 1; i<n; i++){
			int tmp;cin>> tmp;
			if(ok){
				if(tmp>pre_n){
					ans++;
					ok = false;	
					pre_n = tmp;
				}else pre_n = min(pre_n,tmp);
			}else{
				if(tmp<pre_n){
					ans++;
					ok = true;
					pre_n = tmp;
				}else pre_n = max(pre_n,tmp);
			}
		}
		if(ok)ans--;
		cout << ans << endl;
	}
}
