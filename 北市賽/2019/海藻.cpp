#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = unsigned long long;
//#define int ll 
using pii = pair<int,int>;
#define F first
#define S second
#define endl '\n'
ll dp[155] = {0};
bool color(int n,ll k){
	if(n==2)return 1;
	else if(n==1)return 0;
	if(k<=dp[n-2]) return color(n-2,k);
	else return color(n-1,k-dp[n-2]);
}

signed main(){
	io_op
	int m;	
	cin >> m;
	dp[1]=1;dp[2]=1;
	for(int i = 3; i<100; i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	while(m--){
		int n;ll k;
		cin >> n >> k;
		if(dp[n]>=k)cout << color(n,k);
		else cout << "-1";
		cout << endl;
	}
}
