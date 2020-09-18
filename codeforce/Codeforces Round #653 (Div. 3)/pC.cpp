#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	string str;
	cin >> str;
	int r = 0,l=0;
	for(int i = 0; i<n; i++){
		if(str[i]=='(')r++;
		else{
			if(r>0)r--;
			else l++;
		}
	}
	cout << l << endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;cin >> t;while(t--){
		solve();
	}
}
