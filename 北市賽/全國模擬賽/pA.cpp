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

constexpr ll mxN = 1e5+5;
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
	int n;
	int a[mxN];
	int b[mxN];
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> a[i] >> b[i];
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++){
			if(!((a[i]+a[j])%2)&&!((b[i]+b[j])%2)){
				ans++;
			}
		}
	}
	cout << ans << endl;
}
