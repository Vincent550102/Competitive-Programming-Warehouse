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
	string str;
	cin >> str;
	if(str.size()==1){
		cout << "0\n";
		return;
	}else if(str.size()==2){
		if(str[0]==str[1])cout << "1";
		else cout << "0";
		cout << endl;
		return;
	}else if(str.size()==3){
		if(str[0]==str[1]&&str[1]==str[2])cout << "2";
		else if(str[0]==str[1])cout << "1";
		else if(str[1]==str[2])cout << "1";
		else if(str[0]==str[2])cout << "1";
		else cout << "0";
		cout << endl;
		return;
	}
	int cnt = 0;
	if(str[0]==str[1]){
		cnt++;
		str[1]='1';
	}
	for(int i = 1, sz=str.size(); i<sz-1; i++){
		if(str[i-1]==str[i]&&str[i]==str[i+1]&&str[i-1]!='1'&&str[i]!='1'&&str[i+1]!='1'){
			str[i]=str[i+1]='1';
			cnt+=2;
		}else if(str[i]==str[i+1]&&str[i]!='1'&&str[i+1]!='1'){
			str[i+1]='1';
			cnt++;
		}else if(str[i-1]==str[i+1]&&str[i-1]!='1'&&str[i+1]!='1'){
			str[i+1]='1';
			cnt++;
		}
	}
	cout << cnt << endl;
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
