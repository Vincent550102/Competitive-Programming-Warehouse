#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n,k,m;
	while(cin >> n >> k >> m){
		if(!n&&!k&&!m)break;
		vector<ll> v(n);
		for(ll i = 0; i<n; i++){
			v[i] = i+1;
		}
		ll now = 0;
		while(1){
			if(v.size()==m+1)break;
			now+=k;
			now--;
			now%=v.size();
			v.erase(v.begin()+now);
		}
		now+=k;
		now--;
		now%=v.size();
//		cout << now << endl;
		cout << v[now] << endl;
		v.clear();
	}
} 
