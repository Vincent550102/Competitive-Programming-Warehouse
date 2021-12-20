//#pragma GCC optimize("O3,unroll-loops")
//#pragma loop_opt(on)
#include<bits/stdc++.h>

//#define Debuging
#ifdef Debuging
#define io_op
#define debug(x) cerr << "#x " << x << endl;
#else
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x)
#endif

using namespace std;
using pii = pair<int,int>;
using piii = pair<int,pii>;
using ll = long long;
//#define int ll
#define Ft first
#define Sd second
#define All(x) x.begin(),x.end()
#define Vi vector<int>
#define Vl vector<ll>
#define Pb push_back
#define Eb emplace_back
#define endl '\n'
#define _ << " " <<

#define coutv(v) for(auto x:v){\
	cout << x << " ";\
}cout << '\n';

constexpr ll mxN = 1e4;
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

vector<int> edges[501];
bool vis[501];
int in_degree[501];
int ans[501];

int main(){
    int n,m;
    while(cin >> n >> m){
        for(int i = 1; i <= n; ++i){
            in_degree[i] = 0;
            vis[i] = 0;
            edges[i].clear();
        }
        while(m--){
            int a,b;
            cin >> a >> b;
            edges[a].emplace_back(b);
            in_degree[b] += 1;
        }
        for(int i = 1; i <= n; ++i){
            int cur = 0;
            for(int j = 1; j <= n; ++j){
                if(!vis[j] && in_degree[j] == 0){
                    cur = j;
                    break;
                }
            }
            ans[i] = cur;
            vis[cur] = 1;
            for(int j = 0; j < edges[cur].size(); ++j){
                in_degree[edges[cur][j]] -= 1;
            }
        }
        for(int i = 1; i <= n; ++i){
            cout << ans[i];
            if(i < n)cout << ' ';
        }
        cout << '\n';
    }

}
