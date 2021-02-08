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

constexpr ll mxN = 3e5+5;
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

int mgcd(int a,int b){
	return b?mgcd(b,a%b):a;
}
int lastprime[mxN];
bool prime[mxN];
vector<int> pr;

void lineasieve(){
	for(int i = 2; i<mxN; i++){
		if(!prime[i])pr.Pb(i),prime[i]=i;
		for(int p:pr){
			if(i*p>=mxN)break;
			prime[i*p]=p;
			if(i%p == 0)break;
		}
	}
	fill(prime,prime+mxN,0);
	for(int p:pr){
		prime[p] = 1;
	}
}
void solve(){
	int dp[mxN];
	int n; cin >> n;
	Vi v(n+1,0);
	vector<vector<int> > pre(n+1,vector<int>{});
	for(int i = 1; i<=n; i++){
		cin >> v[i];
		dp[i] = (v[i]==1)?1:0;
	}
	
	
	for(int i = 1; i<=n; i++){
		if(prime[i])continue;
		for(int j = i-1; j>=sqrt(i); j--){
//			cerr << i _ j _ mgcd(i,j) << endl;
			if(mgcd(i,j) > 1){
				if(v[i]==v[j]+1) dp[i] = max(dp[i],dp[j] + 1);
			}
		}
	}
	
	
	
	int ans = 0;
	for(int i = 1; i<=n; i++){
		ans = max(ans,dp[i]);
	}
	cout << ans << endl;
}

int main(){
	io_op
	lineasieve();
	int t;cin >> t;while(t--){
		solve();
	}
}
