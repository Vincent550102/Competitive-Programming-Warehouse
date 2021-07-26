#include<bits/stdc++.h>
using namespace std;
constexpr int mxN = 1e5, MOD = 1e9+7;
string ch = "chokudai";
int c2i(char c){
	for(int i = 0; i<8; i++){
		if(ch[i]==c)return i;
	}
	return -1;	
}
char i2c(int in){
	return ch[in];
}

int dp[mxN][8] = {0};
int main(){
	string str;
	cin >> str;
	dp[0][0]=(str[0]=='c');
	for(int i = 1; i<(int)str.size(); i++){
		dp[i][0]=(dp[i-1][0]+(str[i]=='c'))%MOD;
//		cout << dp[i][0] << " ";
	}
//	cout << endl;
	for(int i = 1 ; i<(int)str.size(); i++){
		for(int j = 0; j<8; j++){
			dp[i][j] = max(dp[i][j],dp[i-1][j]);
		}
		if(c2i(str[i])>0){
			dp[i][c2i(str[i])] = (dp[i][c2i(str[i])-1]+dp[i-1][c2i(str[i])])%MOD;
		}
	}
//	for(int i =0 ; i<(int)str.size(); i++){
//		for(int j = 0; j<8; j++){
//			cout << dp[i][j] << " ";
//		}
//		cout <<endl;
//	}	
	cout << dp[(int)str.size()-1][7] << endl;
}
