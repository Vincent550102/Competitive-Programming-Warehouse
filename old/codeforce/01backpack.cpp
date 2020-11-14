#include<bits/stdc++.h>
using namespace std;
int M,N,a[2019],b[2019],dp[2019][2019];
int main(){
    cin >> M >> N;
    for(int i = 0 ; i < N ; i++){
    	cin >> a[i] >> b[i];
	}
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j <= M; j++){
			if(j >= a[i]){
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i]]+b[i]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[N-1][M] << '\n';
}
