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
	int n;cin >> n;
	int c[]={0,0,0};
	for(int i = 0; i<n; i++){
		int tmp;cin >> tmp;
		switch(tmp%3){
			case 0:
				c[0]++;
				break;
			case 1:
				c[1]++;
				break;
			case 2:
				c[2]++;
				break;
		}
	}
	int avg = (c[0]+c[1]+c[2])/3;
	bool notok=1;
	int cnt = 0;
	int now=0;
	int ans =0;
	while(notok){
//		cout << now _ c[now] << endl;
		if(c[now]>avg){
			ans+=c[now]-avg;
			c[(now+1)%3]+=c[now]-avg;
			c[now]=avg;
		}
		if(c[now]==avg){
			cnt++;
			if(cnt==3)notok=0;
		}else{
			cnt = 0;
		}
		now=(now+1)%3;
	}
	cout << ans << endl;
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
