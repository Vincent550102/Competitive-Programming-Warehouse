#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	int coin[50];
	vector<int> dp(500,100000000);
	for(int i = 0; i<4; i++){
		cin >> coin[i];
	}
	dp[0]= 0;
	for(int i = 0; i<N; i++){
		for(int j = 0; j<4; j++){
			dp[i] = min(dp[i],dp[i-coin[j]]+1);
		}
	}
	
	cout <<dp[N-1];
	
}
