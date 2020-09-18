#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e3+5;
using ll = long long;

void solve(){
	int n;cin >> n;
	string str;
	cin >> str;
	vector<bool> v(n,0);
	bool ok = str[0]-'0';
	v[0]=true;
	for(int i = 1; i<n; i++){
		if(ok&&!(str[i]-'0')){
			ok=false;
			v[i]=true;
		}else if(!ok&&(str[i]-'0')){
			ok = true;
			v[i]=true;
		}
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(!v[i])ans++;
		cout << v[i] << " ";
	}
	cout << ans << endl;
	int cnt = 1;
	for(int i = 0; i<n; i++){
		if(v[i])cout << '1';
		else cout << ++cnt;
	}
	cout << endl;
}
int main(){
	int t;cin >> t;while(t--){
		solve();
	}
}
