#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >> t;while(t--){
		int n,k;
		cin >> n >> k;
		int f,s;
		f =1;
		s = k/n;
		int ans = k;
		while(f<=s){
			int plus = s-f+1;
			f = s+1;
			k+=plus;
			s = k/n;
//			cout << k << " ";
		}
		cout << k << endl;
	}
}
