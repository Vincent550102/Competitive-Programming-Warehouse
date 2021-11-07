#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5+5;
const int inf = 1e9;

int dp[mxN] = {inf};
int main(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i = 1; i<=n; i++){
        cin >> v[i];
    }
    dp[1] = v[1];
    dp[2] = v[2];
    dp[3] = v[3]+min(dp[1], dp[2]);
    for(int i = 4; i<=n; i++){
        int tar = inf;
        for(int j = 1; j<=3; j++){
            tar = min(dp[i-j], tar);
        }
        dp[i] = tar + v[i];
        //cout << dp[i] << " ";
    }
    //cout << endl;
    cout << min(dp[n-1],dp[n]) << endl;
}
