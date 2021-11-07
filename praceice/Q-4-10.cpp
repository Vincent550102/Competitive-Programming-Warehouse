#include<bits/stdc++.h>
using namespace std;
int n, m;
using ll = long long;
#define _ <<" "<<
vector<ll> v;
//#define int ll
bool f(int F){
    int cur = F, cnt = 0;
    for(int i = 0; i<n; i++){
        if(cur < v[i]){
            cur = F;
            if(cnt == m || cur < v[i]) return 0;
            cnt++;
        }
        cur -= v[i];
    }
    return 1;
}

signed main(){
    cin >> n >> m;
    v.resize(n);
    for(ll &x:v)
        cin >> x;
    int lb = 1, rb = 1e9;
    /*for(int i = 1; i<=13; i++){
        cout << i _ f(i) << endl;
    }*/
    while(lb<=rb){
        int mb = lb+rb>>1;
        if(f(mb)) rb=mb-1;
        else lb = mb+1;
    }
    cout << lb << endl;

}
