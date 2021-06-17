#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ <<" "<<
#define debug(x) cerr _ #x _ ":" _ x << endl;
int main(){
	int n,q;cin >> n >> q;
	vector<ll> v(n);
	for(ll &x:v){
		cin >> x;
	}
	
	while(q--){
		ll K; cin >> K;
		int off = 0;
		while(1){
			int lb=0,rb=n-1;
			while(lb<=rb){
				int mb = lb+rb>>1;
				if(K<v[mb]) rb = mb-1;
				else lb = mb+1;
			}
//			debug(lb);
//			debug(rb);
//			debug(K);
			if(off==rb+1) break;
			K+=rb+1-off;
			off = rb+1;
		}
		cout << K << endl;
	}
}
