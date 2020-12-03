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

constexpr ll mxN = 1e7;
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
	cin >> n;
	map<int,int> cnt_num;
	Vi v(n);
	bool ok = true;
	for(int i = 0; i<n; i++){
		cin >> v[i];
		if(v[i]!=v[0])ok=false;
	}
	if(ok){ cout << "0\n"; return;}
	int l,r;
	int idx_cnt = 0;
	int a = v[0],b = v[n-1];
	while(v[0]==v[idx_cnt])idx_cnt++;
	l=idx_cnt;
	idx_cnt = n-1;
	while(v[n-1]==v[idx_cnt])idx_cnt--;
	r=idx_cnt;
//	cout << l << r;
	
	Vi nv;
	nv.Pb(v[l]);
	for(int i = l+1; i<=r; i++){
		if(v[i]!=v[i-1])nv.Pb(v[i]);
	}
	
	map<int,int> MP;
	for(auto x:nv){
		MP[x]++;
	}
	
	if(!MP.count(a)||!MP.count(b)){cout << "1\n";return;}
	
	int ans = INT_MAX;
	for(auto x:MP){
		ans = min(x.S,ans);
	}
	cout << ans+1 << endl;
}

int main(){
	io_op
	int T;cin >> T;while(T--){ solver(); }
}
