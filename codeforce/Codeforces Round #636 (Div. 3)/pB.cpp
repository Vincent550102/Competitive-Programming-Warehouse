#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
signed main(){
	int t;cin >> t;while(t--){
		int n;
		cin >> n;
		if((n/2)%2==0){
			cout << "YES\n";
			int sum = 0;
			for(int i = 1; i<=n/2; i++){
				cout << i*2 << " ";
				sum+=i*2;
			}
			for(int i = 1; i<n/2; i++){
				cout << i*2-1 << " ";
				sum-=i*2-1;
			}
			cout << n-1 + n/2;
		}else{
			cout << "NO";
		}
		cout << endl;
	}
}
