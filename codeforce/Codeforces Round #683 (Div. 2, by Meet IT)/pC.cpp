#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using pii = pair<ll,int>;
//#define int ll
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define vi vector<int>
constexpr ll MOD = 1e9+7;
/*
ll pow_mod(int n, int p){
	int rESULt = 1;
	while(p){
		if(p&1) rESULt=(rESULt * n)%MOD;
		n = (n*n)%MOD;
		p>>=1;
	}
	return rESULt;
}
*/



void solver(){
	int n;
	ll W;
	cin >> n >> W;
	vector<pii> v(n);
	vector<ll> pre(n+1);
	for(int i = 0; i<n; i++){
		cin >> v[i].F;
		v[i].S=i;
	}
	sort(ALL(v));
	pre[0]=0;
	for(int i = 1; i<=n; i++){
		pre[i]=pre[i-1]+v[i-1].F;
	}
	vector<pair<ll,pair<int,int>>> ans;
	for(int i = 0; i<=n; i++){
		ll target = W+pre[i];
		int lb = i,rb = n,mb;
		while(rb>=lb){
			mb=lb+rb>>1;
			if(pre[mb]>target)rb=mb-1;
			else lb=mb+1;
		}
		ans.push_back({pre[rb]-pre[i],{i,rb}});
	}
	sort(ALL(ans));
//	cout << ;
	int sz = ans.size();
	if(ans[sz-1].F<(W/2+W%2))cout << "-1\n";
	else{
		cout << ans[sz-1].S.S-ans[sz-1].S.F << endl;
		for(int i = ans[sz-1].S.F+1; i<=ans[sz-1].S.S; i++){
			cout << v[i-1].S+1 << " ";
		}
		cout << endl;
	}
	
//	for(auto x:ans){
//		cout << x.F << " " <<x.S.F << " " <<x.S.S << endl;
//	}
}

int main(){
	int T;cin >> T;while(T--)solver();
}
