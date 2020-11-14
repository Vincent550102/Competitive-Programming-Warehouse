#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define F first
#define S second
constexpr int mxN = 1e6+5e5;

int main(){
	io_op
	int n;
	cin >> n;
	vector<ll> dp(n+1);
	dp[0]=1;
	dp[1]=1;
	for(int i = 2; i<=n; i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	cout << dp[n] << endl;
}
