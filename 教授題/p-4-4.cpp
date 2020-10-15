#include<bits/stdc++.h>
#define io_op ios::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int main(){
	io_op
	int n;cin >> n;
	vector<pii> v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i].S >> v[i].F;
	}
	#define all(x) x.begin(),x.end()
	sort(all(v));
	int ans = 1;
	int n_act = v[0].F;
	for(int i = 1; i<n; i++){
		if(v[i].S>n_act){
			ans++;
			n_act = v[i].F;
		}
	}
	cout << ans << endl;
}
