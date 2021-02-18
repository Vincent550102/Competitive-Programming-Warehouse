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

int ans[mxN];
int v[mxN];

void sol(int l,int r,int d=0){
	if(l>r)return;
	if(l==r){
		ans[l]=d;
		return;
	}
	auto find_maxidx = [&]() -> int{
		int rot_num=INT_MIN;
		int rot_idx=-1;
		for(int i = l; i<=r; i++){
			if(v[i]>rot_num){
				rot_num=v[i];
				rot_idx=i;
			}
		}
		return rot_idx;
	};
	int root = find_maxidx();
	ans[root]=d;
	sol(l,root-1,d+1);
	sol(root+1,r,d+1);
}

void solver(){
	int n;cin >> n;
	for(int i = 0; i<n; i++){
		cin>>v[i];
	}
	sol(0,n-1);
	for(int i = 0; i<n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
