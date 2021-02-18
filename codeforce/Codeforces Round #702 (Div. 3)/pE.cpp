//#pragma GCC optimize("O3,unroll-loops")
//#pragma loop_opt(on)
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

constexpr ll mxN = 1e2+5;
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
	vector<pii> v(n);
	int cnt = 1;
	for(pii &x:v){
		cin >> x.F;
		x.S=cnt++;
	}
	sort(All(v));
	vector<ll> presum(n);
	presum[0]=v[0].F;
	for(int i = 1; i<n; i++){
		presum[i]=presum[i-1]+v[i].F;
	}
	int stop = 0;
	for(int i = n-2; i>=0&&!stop; i--){
		if(presum[i] < v[i+1].F){
			stop=i+1;
		}
	}
	vector<int> ans;
	for(int i =stop; i<n; i++){
		ans.emplace_back(v[i].S);
	}
	sort(All(ans));
	cout << ans.size() << endl;
	for(int x:ans){
		cout << x << " ";
	}
	cout << endl;
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
