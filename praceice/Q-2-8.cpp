#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow_mod(ll x, ll n, ll p){
    if(!n) return 1;
    if(n&1) return x*pow_mod(x,n-1,p)%p;
    else return pow_mod(x,n/2,p)*pow_mod(x,n/2,p)%p;
}

int main(){
    ll n, p;
    cin >> n >> p;
    for(int i = 0; i<n; i++){
        ll tmp;
        cin >> tmp;
        cout << pow_mod(tmp,p-2,p) << " ";
    }
}
