#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	io_op
	string str;
	while(getline(cin,str)){
		int len = str.size();
		string ans;
		for(int i = 0; i<len; i++){
			if('A'<=str[i]&&str[i]<='Z')ans+=str[i]+('a'-'A');
			else if('a'<=str[i]&&str[i]<='z')ans+=str[i]-('a'-'A');
			else ans+=' ';
		}
		cout << ans << endl;
	}
	
} 
