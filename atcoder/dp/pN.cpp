#include<bits/stdc++.h>
using namespace std;
#define int long long

constexpr int mxN = 405;
constexpr int LONGLONG_MAX = 1e17;
int a[mxN],dp[mxN][mxN],pre[mxN];
#define _ <<" "<<

int f(int l,int r) {
	if(r<=l)return 0;
	if(r==l+1){
		dp[l][r] = min(dp[l][r],pre[r]-pre[l-1]);
		return dp[l][r];
	}
	if(dp[l][r]!=LONGLONG_MAX) return dp[l][r]; 
//	cerr << l _ r << endl;// m = 1 2 3
	int num = LONGLONG_MAX;//f(1,3) = f(1,1) + f(2,3) //f(1,3)=f(1,2)+f(3,3)//f(1,3)=f(1,3)+f(4,3)
	for(int m = l; m<r; m++) {
		num = min(num,f(l,m)+f(m+1,r)+pre[r]-pre[l-1]);
	}
	dp[l][r] = min(dp[l][r],num);
	return dp[l][r];
}

signed main() {
	int n;
	cin >> n;
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j<=n; j++) {
			dp[i][j] = LONGLONG_MAX;
		}
	}
	for(int i = 1; i<=n; i++) {
		cin >> a[i];
		pre[i]=i?pre[i-1]+a[i]:a[i];
	}
	cout << f(1,n) << endl;
}
