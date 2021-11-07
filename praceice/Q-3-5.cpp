#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> h(n+1), p(n+1);
    set<pair<int,int>> S;
    S.insert({INT_MAX, 0});
    for(int i = 1; i<=n; i++){
        cin >> h[i];
    }
    for(int i = 1; i<=n; i++){
        cin >> p[i];
    }
    ll ans = 0;

    for(int i = 1; i<=n; i++){
        int tar = h[i]+p[i];
        auto it = S.upper_bound({tar,i});
        if(it==S.end()) ans += i-1;
        else{
            ans += i - it->second -1;
        }
        #define _ <<" "<<
        int tmp = S.begin()->first;
        //cout << it->first _ it->second _ tmp  << endl;

        while(!S.empty() && S.begin()->first<=h[i]) S.erase(S.begin());

        S.insert({h[i], i});
    }
    cout << ans << endl;
}
