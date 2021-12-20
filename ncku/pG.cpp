
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

constexpr ll mxN = 3e5+5;
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

int dp[501][501][26];
int mx[501][501];

int main(){
    io_op
    string s;
    int x;
    cin>>s>>x;
    for(int i = 0; i < s.size(); ++i){
        dp[i][i][s[i]-'A'] = 1;
        mx[i][i] = 1;
    }
    for(int l = 1; l < s.size(); ++l){
        for(int j = 0; j+l < s.size(); ++j){
            for(int k = 0; k < j+l; ++k){
                //[j,k], [k+1, j+l]
                for(int c = 0; c <= 25; ++c){
                    if(dp[j][k][c]>0&&dp[k+1][j+l][c]>0){
                        dp[j][j+l][c] = max(dp[j][j+l][c], dp[j][k][c]+dp[k+1][j+l][c]);
                    }
                    if(dp[j][k][c]>0&&mx[k+1][j+l] >= x){
                        dp[j][j+l][c] = max(dp[j][j+l][c], dp[j][k][c]);
                    }
                    if(dp[k+1][j+l][c]>0&&mx[j][k] >= x){
                        dp[j][j+l][c] = max(dp[j][j+l][c], dp[k+1][j+l][c]);
                    }
                    mx[j][j+l] = max(mx[j][j+l], dp[j][j+l][c]);
                }
            }
            //cout << j << ' ' << j+l << ' ' << mx[j][j+l] << '\n';
        }
    }
    if(mx[0][s.size()-1] >= x){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}

