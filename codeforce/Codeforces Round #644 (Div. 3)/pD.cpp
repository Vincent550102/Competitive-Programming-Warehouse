#include<bits/stdc++.h>
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;
void solve(){
	int n,k;
	cin >> n >> k;
	if(k>=n){
		cout << "1\n";
		return;
	}
	for(int i = sqrt(n)+1; i>=1; i--){
		if(!(n%i))if(n/i<=k){
			cout << i << endl;
			return;
		}
	}
}

int main(){
	IO_OP
	int t;cin >> t;while(t--){
		solve();
	}
}
