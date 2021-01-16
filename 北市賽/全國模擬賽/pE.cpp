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

#define coutv(v) for(auto x:v){\
	cout << x << " ";\
}cout << '\n';

constexpr ll mxN = 2e3+5;
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

vector<string> G1[mxN];
vector<string> G2[mxN];
int N,M;
bool vis1[mxN];
bool vis2[mxN];

bool chk1(int v=0,int u =-1){
	if(vis1[v])return true;
	vis1[v]=1;
	for(int i = 0; i<N; i++){
		if(stoi(G1[v][i])&&i!=u){
			chk1(i,v);
		}
	}
	return false;
}

int main(){
	io_op
	cin >> N;
	for(int i = 0; i<N; i++){
		int tmp;
		cin >> tmp;
	}
	for(int i = 0; i<N; i++){
		string str;cin >> str;
		for(auto x:str)G1[i]+=x;
	}
	cin >> M;
	for(int i = 0; i<M; i++){
		int tmp;
		cin >> tmp;
	}
	for(int i = 0; i<M; i++){
		cin >> G2[i];
	}
	fill(vis1,vis1+N,0);
	fill(vis2,vis2+N,0);
	if(chk1()||chk2())cout << "INF\n";
	else cout << min(N,M) << endl;
	
	
}
