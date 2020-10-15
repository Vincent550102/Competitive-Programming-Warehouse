#include<bits/stdc++.h>
#define io_op ios::sync_with_stdio(0);cin.tie(0);
#define pii pair<ll,ll>
#define F first
#define S second
using namespace std;
using ll = long long;

int main(){
	io_op
	ll n;cin >> n;
	vector<pii> v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i].F;
	}
	for(int i = 0; i<n; i++){
		cin >> v[i].S;
	}
	sort(v.begin(),v.end(),[](pii a,pii b){
		if(a.F<b.F)return true;
		else if(a.F>b.F)return false;
		return a.S<b.S;
	});
	
	ll ans = 0,cnt = 0;
	for(pii x:v){
//		cout << x.F << ' ' <<x.S << endl;
		cnt+=x.F;
		ans+=x.S-cnt;
	}
	cout << ans << endl;
}
