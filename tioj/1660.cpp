#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

bool chk_pad(string str){
	int len = str.size();
	
	for(int i = 0; i<len/2; i++){
		if(str[len-i-1]!=str[i])return false;
	}
//	cerr << "d";
	return true;
}

int main(){
	io_op
	string str;
	while(cin>>str){
		if(chk_pad(str))cout << "palindrome";
		else cout << "not palindrome";
		cout << endl;
	}
	
} 
