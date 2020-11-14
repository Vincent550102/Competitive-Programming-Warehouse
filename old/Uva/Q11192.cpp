#include<bits/stdc++.h>
using namespace std;
int main(){
	while(true){
		int vim;
		cin >> vim;
		if(vim == 0) break;
		string lin;
		cin >> lin;
		int len = lin.size();
		int cut = len/vim;
		for(int i = cut; i<=len; i+=cut){
			for(int j = i-1; j>(i-cut-1); j--){
				cout <<lin[j];
			}
		}
		cout << '\n';
	}
	
}
