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
	bool ok=0;
	int n;cin >> n;
	string str;cin >> str;
	if(str.substr(n-4,4)=="2020")ok=1;
	if(str.substr(0,1)=="2"&&str.substr(n-3,3)=="020")ok=1;
	if(str.substr(0,2)=="20"&&str.substr(n-2,2)=="20")ok=1;
	if(str.substr(0,3)=="202"&&str.substr(n-1,1)=="0")ok=1;
	if(str.substr(0,4)=="2020")ok=1;
	cout << (ok?"YES\n":"NO\n");
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
