#include<bits/stdc++.h>


#define f first
#define s second

int dp[100006][105] = {{}};

using namespace std;
int main(){
	int N;
	cin >> N;
	vector<pair<int,int>> item;
	item.resize(N+2);
	for(int i = 0; i<N; i++){
		cin >> item[i].f >> item[i].s;
	}
	for(int i = 0; i<N; i++){
		for(int j =0; j<=100; j++){
			if(item[i].f <= j){
				if(i-1 < 0)dp[i][j] = item[i].s;
				else if(j - item[i].f<0) dp[i][j] = max(dp[i-1][j], item[i].s);
				else dp[i][j] = max(dp[i-1][j], dp[i-1][j - item[i].f] + item[i].s);
			}else{
				if(i-1<0)dp[i][j] = 0;
				else dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[N-1][100];
}
