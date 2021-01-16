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
	int n;
	cin >> n;
	ll sum = 0;
	vector<pair<ll,pair<int,int> > > G(n+1,{0,{0,0}});
	for(int i = 1; i<=n; i++){
		cin >> G[i].F;
		sum += G[i].F;
		G[i].S.S=i;
	}
	for(int i = 0; i<n-1; i++){
		int a,b;cin >> a >> b;
		G[a].S.F++;
		G[b].S.F++;
	}
	#define plii pair<ll,pii>
	priority_queue<plii/*,vector<plii>,greater<plii> */> pq;
	for(plii x:G){
		if(x == *G.begin())continue;
		x.S.F--;
		if(x.S.F)pq.push(x);
	}
	cout << sum << " ";
	while(!pq.empty()){
		plii u = pq.top();pq.pop();
//		cout << u.F << " : ";
		sum+=u.F;
		cout << sum << " ";
		u.S.F--;
		if(u.S.F)pq.push(u);
	}
	cout << endl;
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
