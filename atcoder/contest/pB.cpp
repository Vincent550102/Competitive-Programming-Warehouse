#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<string> v(4);
	for(string &x:v){
		cin >> x;
	}
	sort(v.begin(),v.end());
	
	if(v==vector<string>{"2B","3B","H","HR"}){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
}
