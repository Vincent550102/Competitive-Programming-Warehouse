#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define _ <<" "<<
#define endl '\n'
using ll = long long;
vector<ll> v;
ll cut(int lb, int rb){
    if(rb-lb<=1)
        return 0;
    ll M = v[lb]+v[rb]>>1;
    int mb = lower_bound(v.begin()+lb, v.begin()+rb, M) - v.begin();
    if(v[mb-1] - v[lb] >= v[rb] - v[mb])
        mb--;
    //cout << lb _ rb _ mb _ v[mb] << endl;
    return cut(lb, mb) + cut(mb, rb) + v[rb] - v[lb];
}

int main(){
    io_op
    ll N, L;
    cin >> N >> L;
    v.resize(N+5);
    v[0] = 0;
    v[N+1] = L;
    for(int i = 1; i<=N; i++)
        cin >> v[i];
    cout << cut(0, N+1) << endl;
}
