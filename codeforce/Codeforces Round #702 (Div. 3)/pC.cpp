//#pragma GCC optimize("O3,unroll-loops")
//#pragma loop_opt(on)
#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using pii = pair<int,int>;
using piii = pair<int,pii>;
using ll = long long;
//#define int ll
#define F first
#define S second
#define All(x) x.begin(),x.end()
#define Vi vector<int>
#define Vl vector<ll>
#define Pb push_back
#define Eb emplace_back
#define endl '\n'
#define _ << " " <<

#define coutv(v) for(auto x:v){\
	cout << x << " ";\
}cout << '\n';

constexpr ll mxN = 1e12+12;
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

vector<ll> tab;

void build(){
	ll n = 1, i = 1;
	while(n<mxN){
		n=i*i*i;
		i++;
		tab.emplace_back(n);
	}
}

bool chk(ll n){
//	ll lb=0,rb=1e4;
	auto it = *lower_bound(All(tab),n);
	return (it==n)?1:0;
}

void solver(){
	ll x;
	cin >> x;
	bool ok = 1;
	for(ll p = 1; p*p*p<x&&ok; p++){
		ll q = x-p*p*p;
//		cout << q;
		if(chk(q))ok=0;
	}
	cout << (ok?"NO":"YES") << endl;
}

int main(){
	io_op
	build();
	int t;cin >> t;while(t--){ solver(); }
}
