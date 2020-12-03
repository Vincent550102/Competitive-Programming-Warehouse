#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	int a;
	vector<int> arr;
	arr.resize(100005);
	int dp[100005];
	cin >> a;
	for(int i = 0 ; i < a ; i++){
		cin >> arr[i];
		dp[i] = 1;
	}
	
	for(int i = 1 ; i < a; i++){
		if(arr[i] >= arr[i-1]){
			dp[i] = dp[i-1] + 1;
		}
	}
	int max = -1; 
	for(int i = 0 ; i < a ; i++){
		if(max < dp[i])max = dp[i];
	}
	cout << max<< '\n';
}
