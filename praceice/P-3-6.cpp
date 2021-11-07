#include<bits/stdc++.h>
using namespace std;
#define Ft first
#define Sd second
#define All(x) x.begin(),x.end()
#define _ <<" "<<
using ll = long long;
int main(){
    ll n, L;
    cin >> n >> L;
    vector<pair<ll, ll>> v(n+2);
    v[0] = {0, 1e9+7};
    v[n+1] = {L, 1e9+8};
    for(int i = 1; i<=n; i++){
        cin >> v[i].Ft;
    }
    for(int i = 1; i<=n; i++){
        cin >> v[i].Sd;
    }
    sort(All(v));
    stack<ll> S;
    S.push(0);
    ll cnt = 0, ans = -1;
    for(int i = 1; i<=n+1; i++){
        while((v[S.top()].Ft+v[S.top()].Sd)<=v[i].Ft){

            //cout << i _ ans _ S.top() _ v[S.top()].Sd _ v[S.top()].Ft+v[S.top()].Sd _ v[i].Ft<< endl;
            ans = max(ans, v[S.top()].Sd);
            cnt++;
            S.pop();
        }
        if(v[i].Ft-v[i].Sd>=v[S.top()].Ft){
            //cout << i _ ans _ S.top() _ v[i].Sd<< endl;
            ans = max(ans, v[i].Sd);
            cnt++;

        }else{
            S.push(i);
        }

    }
    cout << cnt <<endl<< ans <<endl;
}
