#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	int N,W;
	cin >> N >> W;
	vector<ll> dp(W+1,0);
	vector<ll> weight(N+1);
	vector<ll> value(N+1);
	//�T�w�C�ӭ��q�i�H�����̤j���� 
	for(int i = 0; i<N; ++i){
		cin >> weight[i] >> value[i];
	}
	for(int item = 0; item<N; ++item){ //item = 4
		for(int now_wei = W; now_wei>=weight[item]; --now_wei){ //now_wei = 3
			dp[now_wei] = max(dp[now_wei],dp[now_wei-weight[item]] + value[item]);
		}
	}
	cout << dp[W];
	
} 
