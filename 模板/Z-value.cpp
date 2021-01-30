#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;cin >> s;
	vector<int> z(s.size(),0);
	for(int i = 0; i<s.size(); i++){
		int l = 0,r = 0;
		z[i]=max(min(z[i-l],r-i),0);
		while(i+z[i]<s.size() && s[z[i]] == s[i+z[i]]){
			l=i,r=i+z[i],z[i]++;
		}
	}
}
