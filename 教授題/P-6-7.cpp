#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e4;
int dp[mxN][mxN];
int main(){
	//dp[i][j] = dp[i-1][j-1]+1;if s1[i]==s2[j]
	//dp[i][j] = max(dp[i-1][j],dp[i][j-1])
	string s1,s2;
	cin >> s1 >> s2;
	int len1=s1.size(),len2=s2.size();
	for(int i = 0; i<len1; i++){
		for(int j = 0; j<len2; j++){
			if(s1[i]==s2[j])
				dp[i][j] = (i>0&&j>0)?dp[i-1][j-1]+1:1;
			else
				dp[i][j] = (i>0&&j>0)?max(dp[i-1][j],dp[i][j-1]):0;
		}
	}
	cout << dp[len1-1][len2-1];
	
}
