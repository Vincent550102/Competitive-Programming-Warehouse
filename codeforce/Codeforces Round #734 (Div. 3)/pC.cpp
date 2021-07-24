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

constexpr ll mxN = 2e5+5;
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
	int tab[mxN] = {0};
	map<int,int> pretab;
	map<int,Vi> allocate;
	int n,k;
	cin >> n >> k;
	Vi v(n);
	for(int &x:v){
		cin >> x;
		tab[x]++;
	}
//	cout << "-----------------\n";
//	for(int i = 1; i<=n; i++){
//		cout << tab[i] << " ";
//	}
//	cout << "-----------------\n";
	int cnt = 0;
	for(int i = 1; i<=n; i++){
		if(tab[i]>=k){
			pretab[i] = 1;
		}else if(tab[i]<k){
//			cout << "YEE" _ tab[x];
			cnt+=tab[i];
		}
	}
	for(int i = 0; i<n; i++){
		if(tab[v[i]]<k){
			allocate[v[i]].push_back(i);
		}
	}
	Vi ans(n);
	int split = cnt/k;
	cnt = 1;
//	cout << "--\n";
//	coutv(allocate[3]);
	for(auto x:allocate){
		for(int alc:x.S){
			if(split){
				ans[alc] = cnt++;
				if(cnt>k){
					cnt = 1;
					split--;
				}
			}else ans[alc] = 0;
//			if(!alc)cout << "HERE" _ ans[alc] << endl;
		}
	}
	
//	cout << endl << cnt _ k << endl;
	cnt = 1;
	for(int i = 0; i<n; i++){
		int x = v[i];
		if(tab[x]>=k){
			if(pretab[x]){
				ans[i] = pretab[x]++;
				if(pretab[x]>k) pretab[x]=0;
			}else{
				ans[i] = 0;
			}
		}
	}
	for(int x:ans){
		cout << x << " ";
	}
	cout << endl;
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
