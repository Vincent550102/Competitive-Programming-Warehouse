#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e3+5;
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
vector<int> v;
void solve(){
	int n;
	cin >> n;
	v.clear();
	v.resize(n);
	for(int i = 0; i<n; i++){
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	int mx = v[n-1]+v[n-2];
	int k = 0;
	for(int i = 1; i<mx; i++){
		int cnt = 0;
		vector<int> tmp = v;
		for(int j = 0; j<(int)tmp.size(); j++){
			auto p=find(tmp.begin()+j+1,tmp.end(),i-tmp[j]);
			if(p!=tmp.end()){
				cnt++;
				tmp.erase(p);
			}
		}
		k = max(k,cnt);
	}
	cout << k << endl;
}
int main(){
	IO_OP
	int t;cin >> t;while(t--){
		solve();
	}
}
