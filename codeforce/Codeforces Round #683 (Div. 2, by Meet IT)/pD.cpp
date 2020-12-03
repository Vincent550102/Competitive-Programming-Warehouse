#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using pii = pair<ll,int>;
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

int LCS(string s1, string s2){
    vector<int> p[128];
    for (int i = 0; i < s2.size(); ++i)
        p[s2[i]].push_back(i);
    vector<int> v;
    v.push_back(-1);
 
    for (int i = 0; i < s1.size(); ++i)
        for (int j = p[s1[i]].size() - 1; j >= 0; --j){
            int n = p[s1[i]][j];
            if (n > v.back())
                v.push_back(n);
            else
                *lower_bound(v.begin(), v.end(), n) = n;
        }
    return v.size() - 1;
}


void solver(){
	cout << LCS("axxxbb","abab");
}

int main(){
	int T;cin >> T;while(T--)solver();
}
