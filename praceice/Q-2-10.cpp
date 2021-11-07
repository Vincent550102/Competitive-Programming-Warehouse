#include<bits/stdc++.h>
using namespace std;
#define _ <<" "<<
using ll = long long;
int main(){
    ll n, p;
    cin >> n >> p;
    vector<ll> v(n), ps(n, 0);
    multiset<ll> S;
    for(int i = 0; i<n; i++){
        cin >> v[i];
        ps[i] = (i?ps[i-1]:0)+v[i];
        S.insert(ps[i]);
        //cout << ps[i] << " ";
    }
    //cout << endl;
    ll ans = 0;
    for(int i = 0; i<n; i++){
        ll tar = p+(i?ps[i-1]:0);
        auto it = S.lower_bound(tar);
        //cout << (it == S.begin()) << endl;
        if(it==S.end()||it!=S.begin()&&*it>tar) it--;
        //if(it==S.end()) it--;
        ans = max(ans, *it-(i?ps[i-1]:0));
        //cout << *it _ (i?ps[i-1]:0) << endl;
        if(i) S.erase(ps[i-1]);
    }
    cout << ans << endl;
}
