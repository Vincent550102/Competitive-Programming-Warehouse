#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define int long long
const int mxN = 1e4+5;
signed main(){
	int n,sum = 0,y_num;
	cin >> n;
	vector<pair<int,int>> v(n);
	for(int i = 0; i<n; i++){
		int x,y,r;cin >> x >> y >> r;
		v[i]={x,r};
		y_num=y;
		sum+=r;
	}
	sort(v.begin(),v.end());
	int dp1[mxN] = {0};
	for(int i = 0; i<n; i++){
		dp1[i]=(!i?max(v[i].S,0LL):max(dp1[i-1]+v[i].S,0LL));
	}
	for(auto &x:v){
		x.S*=-1;
	}
	int dp2[mxN] = {0};
	for(int i = 0; i<n; i++){
		dp2[i]=(!i?max(v[i].S,0LL):max(dp2[i-1]+v[i].S,0LL));
	}
	cout << (y_num==0?sum:max(*max_element(dp1,dp1+n),sum+*max_element(dp2,dp2+n)));
}
