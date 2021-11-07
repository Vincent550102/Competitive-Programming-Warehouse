#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
vector<ll> v;
#define _ <<" "<<

bool f(int r){
    int cnt = 0;
    for(int i = 0; i<n; i++){
        ll cur = v[i] + r;
        //cout << r _ i _ v[i] _ cur << endl;
        cnt++;
        if(cnt>k) return 0;
        while(1){
            if(i+1<n&&v[i+1]<=cur)
                i++;
            else break;
        }
    }
    return 1;
}

int main(){

    cin >> n >> k;
    v.resize(n);
    for(ll &x:v)
        cin >> x;
    sort(v.begin(), v.end());
    /*for(int i = 1; i<=n; i++){
        cout << i _ f(i) << endl;
    }*/


    int lb = 0, rb = 1e9;
    while(lb<=rb){
        int mb = lb+rb>>1;
        if(!f(mb)) lb = mb+1;
        else rb = mb-1;
    }
    cout << lb << endl;


}
