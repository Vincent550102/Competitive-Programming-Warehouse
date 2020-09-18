#include<bits/stdc++.h>
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
#define F first 
#define S second
#define MK make_pair
using namespace std;
void solve(){
	int n;
	cin >> n;
	int odd = 0,even = 0;
	int odd_mis = 0,even_mis = 0;
	for(int i = 0; i<n; i++){
		int tmp;
		cin >> tmp;
		if(tmp%2){
			odd++;
			if(!(i%2))odd_mis++;
		}else {
			even++;	
			if(i%2)even_mis++;
		}
	}
	if(odd_mis!=even_mis){
		cout << "-1" << endl;
	}else{
		cout << odd_mis <<endl;
	}
}
int main(){
	IO_OP
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
