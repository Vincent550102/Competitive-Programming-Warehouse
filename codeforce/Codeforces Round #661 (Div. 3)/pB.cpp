#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e9+5;
using ll = long long;
void solve(){
	ll n;
	cin >> n;
	vector<ll> a(n),b(n);
	ll min_a=mxN,min_b=mxN;
	for(ll i = 0; i<n; i++){
		cin >> a[i];
		min_a = min(min_a,a[i]);
	}
	for(ll i = 0; i<n; i++){
		cin >> b[i];
		min_b = min(min_b,b[i]);
	}
	ll ans = 0;
	for(ll i = 0; i<n; i++){
		a[i]=a[i]-min_a;
		b[i]=b[i]-min_b;
		ans+=min(a[i],b[i]);
		ans+=abs(a[i]-b[i]);
	}
	cout << ans << endl;
	
}
int main(){
	int t;cin >> t;while(t--){
		solve();
	}
}
