#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
int main(){
	FAST
	int t;cin >> t;while(t--){
		int a,b;
		cin >> a >> b;
		if(a==1){
			cout << "0";
		}else if(a==2){
			cout << b;
		}else{
			cout << b*2;
		}
		cout << endl;
	}
}
