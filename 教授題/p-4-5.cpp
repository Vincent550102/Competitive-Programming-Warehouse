#include<bits/stdc++.h>
#define io_op ios::sync_with_stdio(0);cin.tie(0);
#define pii pair<ll,ll>
#define F first
#define S second
using namespace std;
using ll = long long;
bool cmp(pii a,pii b){
	return a.S*b.F<a.F*b.S;
}

int main(){
	io_op
	ll n;
	cin >> n;
	vector<pii> v(n);
	
	for(ll i = 0; i<n ; i++){
		cin >> v[i].F;
	}
	
	for(ll i = 0; i<n ; i++){
		cin >> v[i].S;
	}
	
	sort(v.begin(),v.end(),cmp);
	ll ans = 0,cnt = 0;
	#define _ <<" "<<
	for(auto x:v){
//		cout << x.F _ x.S << endl;
		cnt += x.S;
		ans+=x.F*cnt;
	}
	cout << ans << endl;
	
}
