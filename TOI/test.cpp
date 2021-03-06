#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin >> str;
	for(int i = 0, sz=str.size(); i<sz; i++){
		string times = "";
		if(isdigit(str[i])){
			do{
				times+=str[i];
				i++;
			}while(isdigit(str[i]));
		}
		if(times=="")times="1";
		for(int j = 0; j<stoi(times); j++){
			cout << str[i];
		}
	}
}
