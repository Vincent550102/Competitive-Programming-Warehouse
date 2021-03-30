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

void solver(){
	int n,k;
	string s;
	cin >> n >> k;
	cin >> s;
	for(int i = 0; i<n; i++){
		if(s[i]=='*'){
			s[i]='x';
			for(int j = i; j<i+k; j++){
				if(s[j]=='*')s[j]='.';
				else break;
			}
			break;
		}
	}
	for(int i = n-1; i>=0; i--){
		if(s[i]=='*'){
			s[i]='x';
			for(int j = i; j>=i-k; j--){
				if(s[j]=='*')s[j]='.';
				else break;
			}
			break;
		}
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(s[i]=='*'){
			s[i]='x';
			for(int j = i; j<i+k&& j<n; j++){
				cout << j;
				ans++;
				if(s[i]=='*')s[j]='.';
				else break;
			}
		}
	}
	cout << s << endl;
	cout << ans << endl;
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
