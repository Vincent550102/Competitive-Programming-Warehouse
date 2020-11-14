#include<bits/stdc++.h>

#define f first
#define s second
#define mk make_pair

using namespace std;

int _mypow(int a,int b){
	int result = 1;
	if( b == 0 ) return 1;
	while(b--){
		result *= a;
	}
	return result;
}
int dpp[2019][2019];
int elo[2019][2019];
int main(){
	int N,M;
	vector<pair<int,int>> item;
	cin >> N >> M;
	long long limHeave = pow(2,M);
	int a,b;
	for(int i = 0; i<N; i++){
		cin >> a >> b;
		a = _mypow(2,a);
		item.emplace_back(mk(a,b));
	}
	for(int i = 0; i<N; i++){
		for(int j = 0; j<=limHeave; j++){
			if(j >= item[i].f){
				elo[i][j] = max(elo[i-1][j],elo[i-1][j-item[i].f]+item[i].s);
//				cout << dp[i][j] << ' ';
			}else{
				elo[i][j] = elo[i-1][j];	
//				cout << dp[i][j] << ' ';
			}
		}
	}
	
	cout << elo[N-1][limHeave];
	
}
