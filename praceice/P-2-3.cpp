#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod_pow(ll x, ll y, ll p){
    if(!y)return 1;
    if(y%2) return (mod_pow(x, y/2, p)*mod_pow(x, y/2, p)%p)*x%p;
    else return mod_pow(x, y/2, p)*mod_pow(x, y/2, p)%p;
}

int main(){
    ll x, y, p;
    cin >> x >> y >> p;
    cout << mod_pow(x, y, p) << endl;
}
