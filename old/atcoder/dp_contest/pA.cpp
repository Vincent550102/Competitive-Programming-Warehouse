#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >>N;
	vector<int> h(N);
	vector<int> dp(N);
	for(int i = 0; i<N; i++){
		cin >> h[i];
	} 
	
	dp[0] = 0;
	dp[1] = abs(h[0] - h[1]);
	for(int i = 2; i<N; i++){
		dp[i] = min(dp[i-1]+abs(h[i-1]-h[i]),dp[i-2]+abs(h[i-2]-h[i]));
	}
	cout << dp[N-1];
}
