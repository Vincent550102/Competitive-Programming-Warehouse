#include<bits/stdc++.h>
using namespace std;
void solve(){
	int x,y,n;
	cin >> x >> y >> n;
	int ans = n/x*x+y;
	if((n/x*x+y)>n)ans-=x;
	cout << ans << endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;cin >> t;while(t--){
		solve();
	}
}
