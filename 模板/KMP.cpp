#include<bits/stdc++.h>
using namespace std;
vector<int> build_fail(const string &a){
	vector<int> f{-1,0};
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
	cin >> a >> b;
	const auto &f = build_fail(b);
	int u = 0;
	for(int i = 0; i<(int)a.size();i++){
		while(u&&a[i]!=b[u])u=f[u];
		if(a[i]==b[u])u++;
		if(u==(int)b.size()){
			cout << "got" << i-u+1 << endl;
			u = f[u];
		}
	}
} 
