#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define Ft first
#define Sd second
int main(){
    map<int, ll> MP;
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        int m, s, t;
        cin >> m >> s >> t;
        MP[s]+=m;
        MP[t+1]-=m;
    }
    ll ans = 0, now = 0;
    for(auto x:MP){
        now+=x.Sd;
        ans = max(now, ans);
    }
    cout << ans << endl;
}
