#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n,m,a[2019],b[2019];
int dp[2019][2019];

int main(){

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<m; i++){
        cin >> b[i];
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout << dp[n-1][m-1];
}
