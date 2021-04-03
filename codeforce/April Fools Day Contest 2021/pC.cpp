#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;cin >> str;
	bool ok = true;
	for(int i = 2; i<str.size(); i++){
		cout << str[i]
		if(str[i]-'A'!=str[i-1]-'A'+str[i-2]-'A') ok = false;
	}
	cout << (ok?"YES":"NO") << endl;
}
