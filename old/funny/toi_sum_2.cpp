#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll a;
int dp[1000000000];
int main(){
	ll ca;
	cin >> ca;
	for(ll i = 0; i<ca; i++){
		cin >> a;
		
		cout << ((a*a)-a+2)/2 % mod;
	}
	
}
