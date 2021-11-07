#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    set<int> S;
    int ans = 0;
    //S.insert();
    for(int i = 0; i<n; i++){
        int tmp;cin >> tmp;
        ans = max(ans, tmp - (*S.begin()));
        S.insert(tmp);
    }
    cout << ans << endl;
}
