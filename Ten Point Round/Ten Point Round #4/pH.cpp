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
int T;

void solver(int cnt){
	string O1,O2;
	int U;
	cin.ignore();
	getline(cin,O1);
	getline(cin,O2);
	cin >> U;
	cout <<"Test "<<cnt <<": ";
//	cerr << O1<< "      "<<O2 << "     "<<U <<endl;
	if(U>T)cout << "Time Limit Exceeded\n";
	else if(O1!=O2)cout << "Wrong Answer\n";
	else cout << "Accepted\n";
}

int main(){
	io_op
	string title;
	getline(cin,title);
	int t;cin >> t;cin>> T;
	cout << title << endl;
	int cnt = 0;
	while(t--){
		solver(++cnt);
	}
}
