#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int,int> MP;
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i];
		MP[v[i]]=v[i];
	}
	int cnt = 0;
	for(auto &x:MP){
		x.second = cnt++;
	}
	for(int x:v){
		cout << MP[x] << " ";
	}
}
