#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using pii = pair<int,int>;
using ll = long long;
//#define int ll
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define vi vector<int>
constexpr ll mxN = 1e7;
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
	int n;
	cin >> n;
	cout << n << endl;
	for(int i = 1; i<=n; i++){
		cout << i << " ";
	}
	cout << endl;
}

int main(){
	int T;cin >> T;while(T--)solver();
}
