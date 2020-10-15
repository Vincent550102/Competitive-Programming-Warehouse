#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define pii pair<int,int>
#define F first
#define S second

int cnt_len(pii a){
	return a.S-a.F;
}

signed main(){
	int n;
	cin >> n;
	vector<pii> v(n);
	for(pii &x:v){
		cin >> x.F >> x.S;
	}
	sort(v.begin(),v.end());
	int ans = cnt_len(v[0]);
	pii last = v[0];
	for(int i = 1; i<n; i++){
		ans+=cnt_len(v[i]);
		if(v[i].F<last.S){
			ans-=last.S-v[i].F;
		}
		if(v[i].S<last.S){
			ans+=last.S-v[i].S;
		}
		if(v[i].S>last.S)last=v[i];
	}
	cout << ans << endl;
}
