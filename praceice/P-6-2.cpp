#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5+5;

int dp[mxN] = {0};
int main(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i = 1; i<=n; i++){
        cin >> v[i];
    }
    dp[1] = v[1];
    dp[2] = max(v[1], v[2]);
    for(int i = 3; i<=n; i++){
        dp[i] = max(dp[i-1], dp[i-2]+v[i]);
        //cout << dp[i] << " ";
    }
    //cout << endl;
    cout << dp[n] << endl;
}
