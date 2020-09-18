#include<bits/stdc++.h>
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	bool flag = false;
	int one_cnt = v[0]%2;
	for(int i = 1; i<n; i++){
		if(v[i]-1 == v[i-1])flag = true;
		one_cnt += v[i]%2;
	}
//	cout << one_cnt;
	if(flag&&one_cnt%2 || (flag||!(one_cnt%2)) ){
		cout << "YES";
	}else cout << "NO";
	cout<< endl;
}

int main(){
	IO_OP
	int t;cin >> t;while(t--){
		solve();
	}
}
