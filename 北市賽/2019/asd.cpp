#include<bits/stdc++.h>
#include<unordered_map> 

using namespace std;
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using pii = pair<int,int>;
#define F first
#define S second
using ll = long long;
constexpr int mxN = 1e2+5;
constexpr ll MOD = 65537;
vector<int> buf[mxN];

int pow_mod(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res=(res * n)%MOD;
		n = (n*n)%MOD;
		p>>=1;
	}
	return res;
}

int main(){
	io_op
	cout << pow_mod(9,MOD);
	
}
