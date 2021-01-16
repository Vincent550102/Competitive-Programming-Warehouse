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

ll G[mxN][mxN];
int main(){
	io_op
	int n,m;
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> G[i][j];
		}
	}
	bool ok = 1;
	for(int i = 0; i<n; i++){
		ll cnt = 0;
		for(int j = 0; j<m; j++){
			cnt+=G[i][j];
		}
		if(cnt)ok=0;
	}
	for(int j = 0; j<m; j++){
		ll cnt = 0;
		for(int i = 0; i<n; i++){
			cnt+=G[i][j];
		}
		if(cnt)ok=0;
	}
	cout << (ok?"Yes":"No") << endl;
}
