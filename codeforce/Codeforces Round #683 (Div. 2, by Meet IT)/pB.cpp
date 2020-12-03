#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using pii = pair<int,int>;
using ll = long long;
//#define int ll
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define vi vector<int>
constexpr ll MOD = 1e9+7;
/*
ll pow_mod(int n, int p){
	int rESULt = 1;
	while(p){
		if(p&1) rESULt=(rESULt * n)%MOD;
		n = (n*n)%MOD;
		p>>=1;
	}
	return rESULt;
}
*/

constexpr int mxN = 15;
int G[mxN][mxN];
int n,m;


void solver(){
	cin >> n >> m;
	bool ok = 0;
	int num = INT_MAX;
	int cnt = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> G[i][j];
			if(G[i][j]<0)cnt++;
			num = min(abs(G[i][j]),num);
		}
	}
	int ans = 0;
	if(cnt%2){
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				ans+=abs(G[i][j]);
			}
		}
		cout << ans-2*num << endl;
	}else{
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				ans+=abs(G[i][j]);
			}
		}
		cout << ans << endl;
	}
}

int main(){
	int T;cin >> T;while(T--)solver();
}
