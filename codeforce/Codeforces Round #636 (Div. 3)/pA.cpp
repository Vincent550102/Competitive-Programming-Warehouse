#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;while(t--){
		int n;
		cin >> n;
		int r = 2;
		for(int i = 1; i<100; i++){
			r*=2;
			if(n%(r-1)==0){
				break;
			}
		}
		cout << n/(r-1) << endl;
	}
}
