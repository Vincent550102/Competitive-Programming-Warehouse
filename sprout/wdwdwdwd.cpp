#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	map<string,int> mp;
	for(int i = 0; i<n; i++){
		string tmp;
		cin >> tmp;
		if(!mp.count(tmp))mp[tmp] = 1;
		else mp[tmp]++;
	}
	for(int i = 0; i<m; i++){
		string tmp;
		cin >> tmp;
		if(mp.count(tmp))cout << mp[tmp];
		else cout << "0";
		cout << endl;
	}
}
