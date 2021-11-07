#include<bits/stdc++.h>
using namespace std;
#define Ft first
#define Sc second
#define All(x) x.begin(),x.end()
using pii = pair<int,int>;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<pii>v(n);
    for(auto &x:v)
        cin >> x.Ft;

    for(auto &x:v)
        cin >> x.Sc;

    sort(All(v), [](pii a, pii b) -> bool{
         return a.Ft*b.Sc<a.Sc*b.Ft;
    });
    ll ans = 0, ps = 0;
    for(int i = 0; i<n; i++){
        ans+=v[i].Sc*ps;
        ps+=v[i].Ft;
    }
    cout << ans << endl;


}
