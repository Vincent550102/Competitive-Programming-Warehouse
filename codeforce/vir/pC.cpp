#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
#define int ll
using pii = pair<int,int>;
#define F first
#define S second
constexpr int mxN = 1e3+5;
bool table[mxN]={0};

void build(){
	for(int i = 2; i<mxN; i++){
		if(!table[i]){
			for(int j = i+i; j<mxN; j+=i){
				table[j]=1;
			}
		}
	}
}

bool comp(pii a,pii b){
	if(a.F==b.F)return a.S<b.S;
	else return a.F<b.F;
}

void solve(){
	int n;
	cin >> n;
	vector<pii> v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i].F;
	}
	for(int i = 0; i<n; i++){
		cin >> v[i].S;
	}
	v.push_back({0,0});
	sort(v.begin(),v.end(),comp);
	int ans = 2e10+5;
	v.push_back({0,0});
	for(int i = n-1; ~i; i--){
		v[i].S += v[i+1].S;
	}
	for(int i = n; ~i; i--){
		ans = min(ans,max(v[i].F,v[i+1].S));
//		cout << v[i].F<<" "<<v[i+1].S<<endl;
	}
	cout << ans << endl;
}
signed main(){
	//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
	//2*2
	io_op
	table[1]=1;
//	build();
	int t;cin >>t;while(t--){
		solve();
	}
	
}
