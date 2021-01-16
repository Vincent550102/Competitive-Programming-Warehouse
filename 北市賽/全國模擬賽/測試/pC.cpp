#pragma GCC optimize("O3,unroll-loops")
#pragma loop_opt(on)
#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
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

#define coutv(v) for(auto x:v){\
	cout << x << " ";\
}cout << '\n';

constexpr ll mxN = 1e3+5;
constexpr ll MOD = 1e9+9;
constexpr ll P = 100100107;
ll pow_mod(ll n, ll p){
	ll rESULt = 1;
	while(p){
		if(p&1) rESULt=(rESULt * n)%MOD;
		n = (n*n)%MOD;
		p>>=1;
	}
	return rESULt;
}

unordered_map<ll,int> MP{};
ll n,m;
bool ok = 0;
ll G[mxN][mxN] = { };
ll dr[] = {0,1};
ll dc[] = {1,0};

void init(){
	ok = 0;
	MP.clear();
}

bool vaild(ll r,ll c){
	return min(r,c)>=0 && r<n && c<m;
}

void dfs(ll r=0,ll c=0,ll d=1,ll h = 0){
	if(ok)return;
	if(r==n-1 && c==m-1) if(MP.count(h)){
		ok = 1;
		return;
	}else{
		MP[h]=1;
		return;
	}
	for(int i = 0; i<2; i++){
		ll nr = r+dr[i];
		ll nc = c+dc[i];
		if(vaild(nr,nc)){
			dfs(nr,nc,d+1,(h+G[nr][nc]*pow_mod(P,d))%MOD);
		}
	}
}

void solver(){
	init();
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> G[i][j];
		}
	}
	dfs();
	cout << (ok?"Yes\n":"No\n");
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
