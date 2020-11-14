#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int mxN = 505;
int dis[mxN][mxN];
const int INF = 1e3;
int main(){//700000
	io_op
	long long n,m;
	while(cin >> n>> m){
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				dis[i][j]=INF;
			}
		}
		assert(m<=7e5);
		assert(n<=5e2);
		for(int i = 0; i<n-1; i++){
			int a,b;cin >> a >> b;
			dis[a][b]=dis[b][a]=1;
		}
		for(int k = 0; k<n; k++){
			for(int i = 0; i<n; i++){
				for(int j = 0; j<n; j++){
					dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		set<pii> S;
		for(int i = 0; i<m; i++){
			int a,b;cin >> a >> b;
			assert(a<n&&b<n);
			if(a<b)swap(a,b);
			S.insert({a,b});
		}
		for(pii x:S){
			cout << dis[x.F][x.S] << endl;	
		}
		
	}
	
}
