#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
	int arr[1000],dp[1000];
	cin >> N;
	for(int i = 0; i<N; i++){
		cin >> arr[i];
		dp[i] = 1;
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j<i; j++){
			if(arr[i] > arr[j]) dp[i] = max(dp[i],dp[j]+1);
		}
	}
	int z = 0;
	for(int i = 0; i < N ; i++){
		z = max(z,dp[i]);
	}
    
    cout << z << '\n';
}
