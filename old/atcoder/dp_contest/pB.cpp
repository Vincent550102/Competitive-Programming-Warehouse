#include<bits/stdc++.h>
#define INF 1e9+5
using namespace std;
int main(){
	int N;
	int K;
	cin >> N >> K;
	vector<int > hei(N);
	vector<int > dp(N,INF);
	for(int i = 0; i<N; ++i){
		cin >> hei[i];
	}
	dp[0] = 0;
	for(int i = 0; i<N; ++i){
		for(int j = i+1; j<=i+K; ++j){
			if(j < N)
				dp[j] = min(dp[j],dp[i]+abs(hei[j] - hei[i]));
		}
	}
	cout << dp[N-1];
}
