#include<bits/stdc++.h>
using namespace std;
int main(){
	map<char,int> lo;
	lo['3']++;
	for(char i = 0; i<9; i++){
		lo[i+'0']++;
		lo['5']++;
	}
	
	/*
	for(auto x = lo.begin(); x != lo.end(); x++){
		cout << x->first <<" : " << x->second << endl;
	}
	*/
	for(auto x : lo){
		cout <<x.first << x.second << endl;
	}
	
	
}
