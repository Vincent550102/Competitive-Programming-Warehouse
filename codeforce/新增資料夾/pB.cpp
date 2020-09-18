#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
#define mk make_pair
using ll = long long;
using namespace std;
void solve(){
	ll a,b,x,y,n;
	cin >> a >> b >> x >> y >> n;
	pair<ll,ll> A = {a,x};
	pair<ll,ll> B = {b,y};
	vector<pair<ll,ll> > v={A,B};
	sort(v.begin(),v.end());
//	#define find_dis(x) x.F-x.S
	if(n<=find_dis(v[0])){
		v[0].F-=n;
	}else{
		n-=(v[0].F-v[0].S);
		v[0].F=v[0].S;
		v[1].F-=n;
	}
	cout << v[0].F*v[1].F << endl;;
}
signed main(){
	io_op
	int t;cin >> t;while(t--){
		solve();
	}
} 
