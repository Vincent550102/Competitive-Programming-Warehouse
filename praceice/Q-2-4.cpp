#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod_pow(ll n, ll y, ll p){
    if(!y) return 1;
    if(y&1) return mod_pow(n, y-1, p)* n%p;
    else return mod_pow(n, y/2,p)*mod_pow(n, y/2, p)%p;
}

int main(){
    string str;
    ll y, p;
    cin >> str >> y >> p;
    ll n = 0;
    for(char c:str){
        n = (c-'0'+10*n)%p;
    }
    cout << mod_pow(n, y, p);
}
