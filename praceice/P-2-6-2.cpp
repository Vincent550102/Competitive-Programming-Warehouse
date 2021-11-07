#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,k;
    cin >> m >> n>> k;
    set<int> S1, S2;
    for(int i = 0; i<m; i++){
        int tmp; cin >> tmp;
        S1.insert(tmp);
    }
    for(int i = 0; i<n; i++){
        int tmp; cin >> tmp;
        S2.insert(tmp);
    }
    int ans = 0;
    for(int x:S1){
        if(*S2.lower_bound(k-x)==k-x) ans++;
    }
    cout << ans << endl;
}
