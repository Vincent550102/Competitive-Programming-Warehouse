#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int u;cin >>u;
	int ans = 0;
	for(int i = 1; i<n; i++){
		int tmp;cin >> tmp;
		ans = max(ans,tmp-u);
		u=tmp;
	}
	cout << ans << endl;
}
