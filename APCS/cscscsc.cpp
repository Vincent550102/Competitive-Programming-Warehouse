#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int,int> MP;
	int t;cin >> t;while(t--){
		int c;
		cin >> c;
	MP[c]++;
	}
	for(auto x:MP){
		cout << x.second;
	}
}
