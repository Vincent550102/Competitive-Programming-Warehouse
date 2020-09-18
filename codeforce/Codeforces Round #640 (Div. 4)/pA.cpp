#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t; while(t--){
		string n;
		cin >> n;
		int len = n.size();
		int cnt = 0;
		for(int i = 0; i<len; i++){
			if(n[i]!='0')cnt++;
		}
		cout << cnt << endl;
		for(int i = 0; i<len; i++){
			if(n[i]!='0'){
				cout << n[i];
				for(int j = 0; j<len-i-1; j++){
					cout << '0';
				}
				cout << " ";
			}
		}
		cout << endl;
	}
}
