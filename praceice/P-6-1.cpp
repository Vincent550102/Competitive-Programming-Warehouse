#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5+5;

int dp[mxN] = {0};
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x:v)
        cin >> x;
    dp[0] = v[0];
    dp[1] = v[1];
    for(int i = 2; i<n; i++){
        dp[i] = min(dp[i-1], dp[i-2])+v[i];
        //cout << dp[i] << " ";
    }
    //cout << endl;
    cout << dp[n-1] << endl;
}
