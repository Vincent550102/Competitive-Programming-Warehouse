#include<bits/stdc++.h>
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

void solve(){
	int a,b;
	cin >> a >> b;
	cout << max(min(a,b)*2,max(a,b))*max(min(a,b)*2,max(a,b)) << endl;
}

int main(){
	IO_OP
	int t;cin >> t;while(t--){
		solve();
	}
}
