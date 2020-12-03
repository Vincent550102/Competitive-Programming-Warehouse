#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin >> n;
	vector<int> p(n);
	iota(p.begin(),p.end(),1);
	for(auto x:p){
		cout <<x << ' ';
	}
} 
