#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >> t; while(t--){
		int n,a,b;
		cin >> n >> a >>b;
		vector<int> aim(n,0);
		for(int i =0 ; i<b-1; i++){
			for(int j = i+1; j<n; j+=a){
				aim[j] = i+1;
			}
		}
		for(int i = 0; i<n; i++){
			cout << (char)('a'+aim[i]);
		}
		cout << endl;
	}
} 
