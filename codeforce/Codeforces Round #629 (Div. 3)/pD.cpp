#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t; while(t--){
		int n;
		cin >> n;
		map<int,int> MP;
		vector<int> ans(n);
		int cnt = 1;
		for(int i = 0; i<n; i++){
			cin >> ans[i];
			if(!MP.count(ans[i])){
				MP[ans[i]] = cnt;
				cnt++;
			}
		}
		for(int x:ans){
			cout << MP[x] << " ";
		}
		cout << endl;
	}
}
