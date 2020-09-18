#include<bits/stdc++.h>
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	int ans = 1e9;
	for(int i = 1; i<n; i++){
		ans = min(ans,abs(v[i]-v[i-1]));
	}
	cout << ans << endl;
}

int main(){
	IO_OP
	int t;cin >> t;while(t--){
		solve();
	}
}
