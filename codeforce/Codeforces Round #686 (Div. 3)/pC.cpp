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
	int pre;
	map<int,int> cnt_num;
	cin >> pre;
	cnt_num[pre]=0;
	int cnt = 0;
	for(int i = 1; i<n; i++){
		int tmp;cin >> tmp;
		if(i==n-1){
			if(!cnt_num.count(tmp))cnt_num[pre]=0;
			else if (pre == tmp) cnt_num[pre]--;
//			cout << cnt_num[pre];
			continue;
		}
		if(tmp==pre)continue;
		if(tmp!=pre){
			cnt_num[tmp]++;
		}
		pre= tmp;
		cnt++;
	}
	int ans = INT_MAX;
	for(auto x:cnt_num){
		ans = min(x.S,ans);
	}
	cout << ((!cnt)?0:ans+1) << endl;
}

int main(){
	io_op
	int T;cin >> T;while(T--){ solver(); }
}
