#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	long long pre;cin >> pre;
	bool flag = false;
	bool isone = true;
	for(int i = 1; i<n; i++){
		long long tmp;cin >> tmp;
		if(flag || tmp==pre)flag = true;
		else if(!flag){
			if(abs(tmp-pre)>1)isone=false;
		}
		pre = tmp;
	}
	if(flag){
		cout << 2;
	}else{
		if(isone)cout << 1;
		else cout << 0;
	}
}
