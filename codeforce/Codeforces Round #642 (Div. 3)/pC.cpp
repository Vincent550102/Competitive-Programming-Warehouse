#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
#define ALL(x) x.begin(),x.end()
using ll = long long;
#define int ll
signed main(){
	FAST
	int t;cin >> t;while(t--){
		int n;
		cin >> n;
		int cnt = 0;
		int sum = 0;
		for(int i = 1; i<=n; i+=2){
			sum += (i*i - (i-2)*(i-2))*cnt;
			cnt++;
		}
		cout << sum << endl;
	}
}
