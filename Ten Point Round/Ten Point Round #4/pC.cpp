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
	int r,c;
	cin >> r >> c;
	for(int i = 0 ;i<r; i++){
		cout << "*";
	}
	cout << endl;
	for(int i = 0; i<c-2; i++){
		cout << "*";
		for(int j = 0; j<r-2; j++){
			cout << " ";
		}
		cout << "*\n";
	}
	for(int i = 0 ;i<r; i++){
		cout << "*";
	}
	cout << endl;
	cout << "Use " << r*c-(r-2)*(c-2)<<" fences\n";
}

int main(){
	io_op
	int cnt = 0;
	int t;cin >> t;while(t--){
		cout << "Case " << ++cnt <<":\n";
		solver();
	}
}
