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
vector<ll> MP[mxN];
signed main(){
    io_op
    int d,n,k;
    cin >> d >> n >> k;

    for(int i = 0; i<n; i++){
        int c, s, t;cin >> c >> s >> t;
        MP[s].Pb(c);
        MP[t+1].Pb(-c);
    }
    multiset<ll> A, B;
    int cnt = 0;
    ll ans = 0, num = 0;
    /*for(int i = 0; i<=d+1; i++){
        cout <<  (MP[i].size()) << " ";
        if(!MP[i].size()) break;

    }*/
    for(int i = 0; i<=d+1; i++){
        /*for(int tmp : MP[i]){
            cout << tmp << " ";
        }
        cout << endl;*/

        if(!MP[i].size())continue;
        //cout << !MP[i].size() << " ";
        //cout << MP[i].size() << "\n";
        auto x = MP[i];
        for(ll c:x){
            if(c>0){
                A.insert(c);
                cnt++;
                num+=c;
                if(cnt>k){
					cnt--;
                    num -= *A.begin();
                    B.insert(*A.begin());
                    A.erase(A.begin());
                }
            }else{
                if(B.empty()){
                    cnt--;
                    num+=c;
                    A.erase(A.lower_bound(-c));
                }else{
                    if(B.find(-c)!=B.end()){
                        B.erase(B.lower_bound(-c));
                    }else{
                        A.erase(A.lower_bound(-c));
                        num+=c;
                        A.insert(*(--B.end()));
						num+=*(--B.end());
						B.erase(--B.end());
                    }
                }
            }
        }

        /*cout << "A : ";
        for(auto x = A.begin(); x!=A.end(); x++){
            cout << *x << " ";
        }
        cout << endl << "B: ";
        for(auto x = B.begin(); x!=B.end(); x++){
            cout << *x << " ";
        }
        cout << endl;*/
        ans = max(ans, num);
    }
    cout << ans << endl;
}
