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

int n,k;

int main(){
	io_op
	cin >> n >> k;
	Vi v(n);
	for(int i = 0;i <n; i++){
		cin >> v[i];
	}
	int ans = 0;
	#define _ << " " << 
	for(int i = 0; i<n; i++){
		int mx = v[i];
		int mi = v[i];
		for(int j = i; j<n; j++){
			auto upd = [&](){
				mx = max(mx,v[j]);
				mi = min(mi,v[j]);
			};
			upd();
			if(mx-mi<=k)ans++;
			else break;
		}
	}
	cout << ans <<endl;
	
}
