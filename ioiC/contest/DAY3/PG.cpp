#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int* build_fail(const string &a){
	int f[1000],u;
	f[0] = u=-1;
	for(int i = 1; i<(int)a.size(); i++){
		while(u!=-1&&a[i] != a[u+1])u=f[u];
		if(a[i]==a[u+1])u++;
		f[i] = u;
	}
	return f;
}

int main(){
	io_op
	string s1 = "aabaabaaaabaabaa";
	string s2 = "ababac";
	int* f = build_fail(s2);
	for(int i = 0; i<s2.size(); i++){
		cout << f[i] << " ";
	}
	cout << endl;
	for(int i = s2.size()-1; i>=0; i--){
		cout << f[i] << " ";
	}
	cout << endl;
	for(int i = s2.size()-1; i>=0; i--){
		cout << f[i]+f[s2.size()-i-1] << " ";
	}
	cout << endl;
}
