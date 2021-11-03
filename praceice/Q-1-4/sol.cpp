#include<bits/stdc++.h>
#define _ <<' '<<
#define mxN 50002
using namespace std;
using ll = long long;
int N, K;
ll v[mxN];
ll L2Rprefixv[mxN]={0};
ll L2Rsum[mxN]={0};
ll R2Lprefixv[mxN]={0};
ll R2Lsum[mxN]={0};


ll findLrang(int l, int r){
    //if(l==r)return 0;
    //cout << l _ r _ (r-l+1)*(l?L2Rprefixv[l-1]:0) << endl;
    return L2Rsum[r] - (l?L2Rsum[l-1]:0)- (r-l+1)*(l?L2Rprefixv[l-1]:0);
}
ll findRrang(int l, int r){
    //if(l==r)return 0;
    //cout << l _ r _  (l-r+1)*(r!=N-1?R2Lprefixv[r+1]:0)<< endl;
    return R2Lsum[l] - (r<N-1?R2Lsum[r+1]:0) - (r-l+1)*(r<N-1?R2Lprefixv[r+1]:0);
}

ll cut(int lb, int rb, int d = 0){
    if(d == K || rb - lb < 2) return 0;
    ll mnmb = 2e18;
    int mb;
    for(int i = lb+1; i<rb; i++){
        ll tmp = abs(findLrang(lb, i-1) - findRrang(i+1, rb));
        //cout << i _ tmp _ findLrang(lb, i-1) _ findRrang(i+1, rb)<< endl;
        if(tmp < mnmb){
            mnmb = tmp;
            mb = i;
        }
    }
    //cout << mb << endl;
    return cut(lb, mb-1, d+1) + cut(mb+1, rb, d+1) + v[mb];

}

int main(){

    cin >> N >> K;
    for(int i = 0; i<N; i++){
        cin >> v[i];
        L2Rprefixv[i] = (i?L2Rprefixv[i-1]:0) + v[i];
        L2Rsum[i] = L2Rprefixv[i] + (i?L2Rsum[i-1]:0);
    }
    for(int i = N-1; i>=0; i--){
        R2Lprefixv[i] = (i<N-1?R2Lprefixv[i+1]:0) + v[i];
        R2Lsum[i] = R2Lprefixv[i] + (i<N-1?R2Lsum[i+1]:0);
    }/*
    for(int i = 0; i<N; i++){
        cout << i _ L2Rprefixv[i] _ L2Rsum[i] _ R2Lprefixv[i] _ R2Lsum[i] << endl;
    }*/
    cout << cut(0, N-1) << endl;
}
