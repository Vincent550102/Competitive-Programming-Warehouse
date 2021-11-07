#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
#define Ft first
#define Sd second
#define lb(x) x&-x
#define _ <<" "<<
int n;
struct BIT{
    vector<ll> v;
    void modify(int i, ll d){
        while(i<=n){
            v[i]+=d;
            i+=lb(i);
        }
    }
    ll query(int i){
        ll sum = 0;
        while(i){
            sum+=v[i];
            i-=lb(i);
        }
        return sum;
    }
};
int main(){
    cin >> n;
    vector<pii> v(n);
    for(int i = 0; i<n; i++){
        cin >> v[i].Ft;
        v[i].Sd = i+1;
    }
    sort(v.begin(), v.end(), [](pii a, pii b){
         return (a.Ft==b.Ft)?a.Sd>b.Sd:a.Ft>b.Ft;
    });
    ll ans = 0;
    BIT bit;
    bit.v.resize(n+1, 0);
    for(pii x:v){
        //cout << x.Ft _ x.Sd << endl;
        bit.modify(x.Sd, 1);
        ans+=bit.query(x.Sd-1);
    }
    //cout << endl;
    cout << ans << endl;

}
