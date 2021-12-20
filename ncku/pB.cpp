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

int main(){
    int n;cin >> n;
    vector<pii> v(n);
    int cnter = 0;
    for(auto &x:v){
        cin >> x.Ft;
        x.Sd = ++cnter;
    }

    sort(All(v));
    int lb = 0;
    while(!v[lb].Ft){
        lb++;
    }
    int rb = n-1;
    vector<pair<pii,int>> ans;
    int cnt = 0;
    //cout << lb << endl;
    while(1){
        if(lb>=rb) break;
        while(v[rb].Ft){

            if(v[lb].Ft>v[rb].Ft){
                ans.Pb({{lb,rb},v[rb].Ft});
                cnt+=v[rb].Ft;
                v[lb].Ft-=v[rb].Ft;
                v[rb].Ft = 0;
                break;
            }
            v[rb].Ft-=v[lb].Ft;
            ans.Pb({{lb,rb},v[lb].Ft});
            v[lb].Ft = 0;
            cnt+=lb;
            lb++;
            if(lb>=rb) break;
        }
        rb--;
    }
    int ok = true;
    for(int i = 0; i<v.size(); i++){
        if(v[i].Ft){
            if(v[i].Ft%2) ok = false;
            else{
                ans.Pb({{i,i},v[i].Ft/2});
            }
            //cout << v[i].Ft;
        }
    }
    //cout << endl;
    int anssum = 0;
    for(auto x:ans){
        anssum += x.Sd;
    }
    if(!ok){
        cout << "-1\n";
    }else{
        cout << anssum << endl;
        for(int i = 0; i<ans.size(); i++){
            for(int j = 0; j<ans[i].Sd; j++){
                cout << v[ans[i].Ft.Ft].Sd << " " << v[ans[i].Ft.Sd].Sd << endl;
            }
        }
    }

}
