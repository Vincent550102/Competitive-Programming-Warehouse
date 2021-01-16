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

constexpr ll mxN = 1e5+5;
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

ll ans = 0;
ll cnt = 0,num=0;

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
	if(a.F==b.F)return a.S<b.S;
	else return a.F<b.F;
}

int main(){
	io_op
	int n;
	cin >> n;
	vector<pair<ll,ll> > v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i].F >> v[i].S;
		v[i].F%=2;
		v[i].S%=2;
	}

	sort(All(v),cmp);

	for(int i = 0; i<n; i++){
		if(i==n-1) num = n;
		if(!v[i].F){
			if(v[i].S)cnt++;
		} else {
			num = i;
			break;
		}
	}
	ll tmp = max(0ll,(num-cnt));
	#define _ << " " << 
	ans += max(0ll,cnt*(cnt-1)/2);
	ans += max(0ll,tmp*(tmp-1)/2);
	
	cnt = 0;
	for(int i = num; i<n; i++){
		if(v[i].S)cnt++;
	}
	
	num = n-num;
	tmp = max(0ll,(num-cnt));
	ans += max(0ll,cnt*(cnt-1)/2);
	ans += max(0ll,(tmp)*(tmp-1)/2);
//	assert(ans<=7);	
	cout << ans <<endl;
}
