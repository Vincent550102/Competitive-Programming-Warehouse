#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	vector<int > dp(3);
	cin >> N;
	for(int day = 0; day<N; ++day){
		vector<int > c(3);
		vector<int > new_dp(3,0);
		for(int i = 0; i<3; i++){
			cin >> c[i];
		}
		// new_dp«Øªí 
		for(int i = 0; i<3; ++i){
			for(int j = 0; j<3; ++j){
				if(i != j)
					new_dp[i] = max(new_dp[i],c[i]+dp[j]);
			}
		}
		dp = new_dp;
	}
	cout << max({dp[0],dp[1],dp[2]});
}
