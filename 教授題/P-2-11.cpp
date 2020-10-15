#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll 
signed main(){
	int n,k;
	cin >> n >> k;
	vector<int> v(n),ps(n);
	int sum = 0;
	int ans = 0;
	set<int> S({0});
	for(int i = 0; i<n; i++){
		cin >> v[i];
		sum += v[i];
		ps[i] = sum;
		auto lps = S.lower_bound(ps[i]-k);
		if(lps!=S.end())
			ans = max(ans,ps[i]-*lps);
		S.insert(ps[i]);
	}
	cout << ans << endl;
}
