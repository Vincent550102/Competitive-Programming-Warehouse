#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	int n;
	cin >> str >> n, n--;
	string bstr = str;
	while(next_permutation(str.begin(),str.end()) && str != bstr){
		;
	}
	do{
		;
	}while(n--&&next_permutation(str.begin(),str.end()));
	
	cout << str << endl;
}
