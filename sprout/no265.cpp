#include<bits/stdc++.h>
using namespace std;
vector<int> build_fail(const string &a){
	vector<int> f{0,0};
	int u = 0;
	for(int i = 1; i<(int)a.size(); i++){
		while(u&&a[i]!=a[u])u=f[u];
		if(a[i]==a[u])u++;
		f.push_back(u);
	}
	return f;
}
int main(){
	string a,b;
	cin >> b >> a;
	const auto &f = build_fail(b);
	int u = 0;
	vector<int> ans;
	for(int i = 0; i<(int)a.size();i++){
		while(u&&a[i]!=b[u])u=f[u];
		if(a[i]==b[u])u++;
		if(u==(int)b.size()){
			ans.push_back(i-u+1);
			u = f[u];
		}
	}
	for(int i = 0; i<ans.size();i++){
		cout << ans[i];
		if(i!=ans.size()-1)cout << " ";
	}
	cout << endl;
} 
