#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >> t;while(t--){
		vector<string> grix(9);
		for(int i = 0; i<9; i++){
			string str;
			cin >> str;
			grix[i] = str;
		}
		for(auto x:grix){
			for(auto y:x){
				cout << ((y=='4')?'5':y);
			}
			cout << endl;
		}
	}
}
