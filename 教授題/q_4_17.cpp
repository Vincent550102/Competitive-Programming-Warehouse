#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
void solve(){
	int n;
	cin >> n;
	vector<pii> v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i].S;
	}
	for(int i = 0; i<n; i++){
		cin >> v[i].F;
	}
	sort(v.begin(),v.end());
	int sum=0;
	bool ok = true;
	for(auto x:v){
		int d = x.F,t = x.S;
		sum+=t;
		if(sum>d){
			ok = false;
			break;
		}
	}
	cout << (ok?"yes":"no") << endl;
}
int main(){
	io_op
	int t;cin >> t;while(t--)solve();
}
