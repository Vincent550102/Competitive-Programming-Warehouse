#pragma GCC optimize("O3,unroll-loops")
#pragma loop_opt(on)
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

constexpr ll mxN = 1e4;
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
	int n;cin >> n;
	map<int,int> MP{};
	for(int i = 0; i<n; i++){
		int tmp;cin >> tmp;
		MP[tmp]++;
	}
	Vi v;
	for(auto x:MP){
		v.Eb(x.F);
	}
	ll ans = 0;
	for(int i = 0,sz=v.size();i<sz-2; i++){
		if(v[i+2]-v[i]<=2){
			int cnt =0;
			cnt+=MP[v[i]];
			cnt+=MP[v[i+1]];
			cnt+=MP[v[i+2]];
			ans+=cnt*(cnt-1)*(cnt-2)/6;
		}
		cout << ans << " ";;
	}
	cout << ans << endl;
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
