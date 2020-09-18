#include<bits/stdc++.h>
using namespace std;
int dp[3005][3005];
string dpa[3005][3005];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s,t;
	cin >> s >> t;
	int lens= s.size();
	int lent= t.size();
	for(int i = 1; i<=lens; i++){
		for(int j = 1; j<=lent; j++){
			dp[i][j] = 0;
		}
	}
	for(int i = 1; i<=lens; i++){
		for(int j = 1; j<=lent; j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
				dpa[i][j]=dpa[i-1][j-1]+s[i-1];
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				if(dp[i-1][j]>=dp[i][j-1]) dpa[i][j]=dpa[i-1][j];
				else dpa[i][j]=dpa[i][j-1];
			} 
		}
	}
//	for(int i = 1; i<=lens; i++){
//		for(int j = 1; j<=lent; j++){
////			cout << dp[i][j] << " ";
//		}
////		cout << endl;
//	}
	cout << dpa[lens][lent] << endl;
}

