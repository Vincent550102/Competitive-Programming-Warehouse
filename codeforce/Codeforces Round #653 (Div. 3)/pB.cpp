#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int cnt = 0;
	bool ok = false;
	while(n>=1){
		if(n==1){
			ok = true;
			break;
		}
		if(!(n%6))n/=6;
		else n*=2;
		cnt++;
	}
	if(ok)cout << cnt;
	else cout << "-1";
	cout << endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;cin >> t;while(t--){
		solve();
	}
}
