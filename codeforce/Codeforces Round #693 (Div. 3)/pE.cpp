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

struct DSU{
	Vi p;
	void init(int n){
		p.clear();
		p.resize(n);
		for(int i = 0; i<n; i++){
			p[i]=i;
		}
	}
	int query(int x){
		return p[x] = x==p[x]?x:p[x];
	}
	void Union(int a,int b){
		p[query(a)]=p[query(b)];
	}
};

bool comp(pii a,pii b){
	if((a.F>b.F&&a.S>b.S)||(a.F>b.S&&a.S>b.F))return true;
	else{
		if(a.F>b.F||a.S>b.S)return true;
		else return false;
	}
}

bool comp2(piii a, piii b){
	pii na = a.S;
	pii nb = b.S;
	return comp(na,nb);
}

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
	vector<piii> v(n);
	int cnt = 0;
	for(auto &x:v){
		cin >> x.S.F >> x.S.S;
		x.F=cnt++;
	}
	sort(All(v),comp2);
	Vi ans(n);
	piii cur = v[n-1];
	for(piii x:v){
		if(comp(x.S,cur.S))ans[x.F]=cur.F+1;
		else ans[x.F]=-1;
	}
//	cout << cur.S.F _ cur.S.S << endl;
	for(int x:ans)cout << x << " ";
	
	cout << endl;
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
