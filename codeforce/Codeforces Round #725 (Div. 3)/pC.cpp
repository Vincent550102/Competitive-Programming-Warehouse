#pragma GCC optimize("O3,unroll-loops")
#pragma loop_opt(on)
#include<bits/stdc++.h>

//#define Debug
#ifdef Debug
#define io_op
#define debug(x) cerr << "#x " << x << endl;
#else
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x)
#endif

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

constexpr ll mxN = 2e5+5;
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
int ans = 0;
int n,L,R;
int v[mxN];
ll hashhash(ll a,ll b){
	return a*mxN+b;
}
//unordered_map<ll,int> MP;
set<int> S;
void dfs(int lb = 0,int rb = n-1){
	if(lb>=rb||MP.count(hashhash(lb,rb)))return;
//	cout << lb _ rb << endl;
	ll now = v[lb]+v[rb];
	if(now<L) dfs(lb+1,rb);
	else if(now>R) dfs(lb,rb-1);
	else{	
		ans++;
		MP[hashhash(lb,rb)]=1;
		dfs(lb+1,rb);
		dfs(lb,rb-1);
	}
}

void solver(){
	cin >> n >> L >> R;
	for(int i = 0; i<n; i++){
		cin >> v[i];
	}
	sort(v,v+n);
	ans = 0;
	MP.clear();
	dfs();
	cout << ans << endl;
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
