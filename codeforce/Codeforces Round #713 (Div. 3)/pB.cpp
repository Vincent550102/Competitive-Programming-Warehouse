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

constexpr ll mxN = 1e3;
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
	char G[mxN][mxN];
	pii P[2];
	int cnt = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >> G[i][j];
			if(G[i][j]=='*'){
				P[cnt++]={i,j};
			}
		}
	}
	auto vaild = [&](int r, int c)-> bool{
		return min(r,c)>=0&&max(r,c)<n;
	};
	if(P[0].F==P[1].F){
		// same r
		if(vaild(P[0].F-1,P[0].S)){
			G[P[0].F-1][P[0].S]='*';
			G[P[1].F-1][P[1].S]='*';
		}else{
			G[P[0].F+1][P[0].S]='*';
			G[P[1].F+1][P[1].S]='*';
		}
	}else if(P[0].S==P[1].S){
		// same c
		if(vaild(P[0].F,P[0].S-1)){
			G[P[0].F][P[0].S-1]='*';
			G[P[1].F][P[1].S-1]='*';
		}else{
			G[P[0].F][P[0].S+1]='*';
			G[P[1].F][P[1].S+1]='*';
		}
	}else{
		G[P[0].F][P[1].S]='*';
		G[P[1].F][P[0].S]='*';
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cout << G[i][j];
		}
		cout << endl;
	}
			
	
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
