//#pragma GCC optimize("O3,unroll-loops")
//#pragma loop_opt(on)
#include<bits/stdc++.h>

//#define Debuging
#ifdef Debuging
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
	string tab, str;
	cin >> tab >> str;
	map<char, int> MP;
	int cnt = 0;
	for(char t : tab){
        MP[t] = cnt++;
	}
	int ans = 0;
    for(int i = 0; i<str.size(); i++){
        ans += abs(MP[str[i]]-(i?MP[str[i-1]]:MP[str[i]]));
    }
    cout << ans << endl;
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}