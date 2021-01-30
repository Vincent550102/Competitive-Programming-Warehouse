#include<bits/stdc++.h>
using namespace std;
const int mxN = 2e6+5;
int f[mxN];

vector<int> val(string s){
	vector<int> z(s.size(),0);
	int l=0,r=0;
	for(int i = 0; i<s.size(); i++){
		z[i]=max(min(z[i-l],r-i),0);
		while(i+z[i]<s.size() && s[z[i]] == s[i+z[i]]){
			l=i,r=i+z[i],z[i]++;
		}
	}
	return z;
}

int main(){
	
	int t;cin >> t;while(t--){
		int n;cin >> n;
		for(int i = 0; i<n; i++){
			cin >> f[i];
			f[i]++;
		}
		string s;
		int cnt = 0;
		for(int i = 0 ;i<n; i++){
			if(f[i]==0){
				s+=('a'+cnt);
				cnt++;
			}else{
				s+=s[f[i]-1];
			}
		}
		cerr << s << endl;
		vector<int> ans = val(s);
		for(int x:ans){
			cout << x << " ";
		}
		cout << endl;
	}
	
}
