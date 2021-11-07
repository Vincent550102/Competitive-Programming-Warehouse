#include<bits/stdc++.h>
using namespace std;
const int mxN = 505;
int main(){
    int dp[mxN][mxN] = {0};
    string str1, str2;cin >> str1 >> str2;
    int sz1 = str1.size(), sz2 = str2.size();

    for(int i = 1; i<=sz1; i++){
        for(int j = 1; j<=sz2; j++){
            if(str1[i]==str2[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[sz1][sz2] << endl;

}
