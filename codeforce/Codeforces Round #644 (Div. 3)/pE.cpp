#include<bits/stdc++.h>
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;
int main(){
	IO_OP
	int t;cin >> t;while(t--){
		int n;
		cin >> n;
		vector<int> G[55];
		for(int i = 0; i<n; i++){
			G[i].clear();
		}
		for(int i = 0; i<n; i++){
			G[i].resize(n);
		}
		
		for(int i = 0; i<n; i++){
			string str;cin >> str;
			for(int j = 0; j<n; j++){
				G[i][j] = str[j]-'0';
			}
		}
//		for(auto x:G){
//			for(auto y:x){
//				cout << y << " ";
//			}
//			cout << endl;
//		}
		bool ok = true;
		for(int i = 0; i<(n-1); i++){
			for(int j = 0; j<(n-1); j++){
				if(G[i][j] && !G[i+1][j] && !G[i][j+1])ok = false;
			}
		}
		if(ok)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
