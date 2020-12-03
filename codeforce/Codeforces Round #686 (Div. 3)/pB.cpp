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
	map<int,int> MP;
	map<int,int> to_index;
	for(int i = 0; i<n; i++){
		int tmp ;cin >> tmp;
		MP[tmp]++;
		to_index[tmp]=i+1;
	}
	for(auto x:MP){
//		cout << x.S;
		if(x.S!=1)continue;
		cout << to_index[x.F]<< "\n";
		return; 
	}
	cout << "-1\n";
}

int main(){
	io_op
	int T;cin >> T;while(T--){ solver(); }
}
