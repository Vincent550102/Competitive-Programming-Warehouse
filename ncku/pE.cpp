
//#pragma GCC optimize("O3,unroll-loops")
//#pragma loop_opt(on)
#include<bits/stdc++.h>
#include "lib0113.h"

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
#define Ft first
#define Sd second
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

constexpr ll mxN = 3e5+5;
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

int main(){
    int n = Init();
    int zeros = 0, ones = 0;
    for(int i = 1; i <= n; ++i){
        int res = Query(i, 1, 1);
        if(res == 1)++ones;
        else ++zeros;
    }
    if(ones > zeros){
        Fix(1);
    }else{
        int l = 2, r = n;
        while(l < r){
            int mid = (l+r)/2;
            int res = Query(1, l, mid);
            if(res == 1){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        Fix(l);
    }
}
