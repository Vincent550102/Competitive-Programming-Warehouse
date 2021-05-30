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

int main(){
	io_op
	int one_moun_num[] = {1000,31,28,31,30,31,30,31,31,30,31,30,31};
	int t;cin >> t;
	while(t--){
		int y,m,d;cin >> y >> m >> d;
		//2022/1/21 365+21 = 386
		if(y==2022){
			cout << 21-d << endl;
		}else{
			int d_sum = d;
			for(int i = 1; i<m; i++){
				d_sum+=one_moun_num[i];
			}
			cout << 386-d_sum << endl;
		}
	}
}
