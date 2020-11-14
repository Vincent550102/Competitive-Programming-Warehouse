#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    int arr[1005];
    int dp[1005][5];
    cin >> a;
    for(int i = 0 ; i < a ; i++){
        cin >> arr[i];
    }
    for(int i = 0 ; i < a ; i++){
        dp[i][0] = dp[i][1] = dp[i][2] = 123;
    }
    for(int i = 0 ; i < a ; i++){
        dp[i][0] = min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]) + 1;
        if(arr[i] == 1 || arr[i] == 3){
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
        }
        if(arr[i] == 2 || arr[i] == 3){
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
        }
    }
    cout << min(min(dp[a-1][0],dp[a-1][1]),dp[a-1][2]) << '\n';
}
