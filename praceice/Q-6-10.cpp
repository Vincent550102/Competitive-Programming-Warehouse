#include<bits/stdc++.h>
using namespace std;
const int mxN = 2e5+5;
int dp[105][mxN] = {0};
int main(){
    int n, M, S;
    cin >> n >> M >> S;
    vector<int> v(n+1);
    int sum = 0;
    for(int i = 1; i<=n; i++){
        cin >> v[i];
        sum+=v[i];
    }
    int need = S-M+sum;
    for(int i = 1; i<=n; i++){
        for(int j = 0; dp[i][j]<=need; j++){
            if(j-v[i]>=0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]]+v[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=need; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[n][need] << endl;
}
