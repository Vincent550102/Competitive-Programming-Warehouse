#include<bits/stdc++.h>
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
#define F first 
#define S second
#define MK make_pair
using namespace std;

void solve(){
	string a;
	cin >> a;
	if((int)a.size()==2){
		cout << a <<endl;
		return;
	}
	cout << a[0];
	for(int i = 1; i<(int)a.size()-1; i+=2){
		cout<<a[i];
	}
	cout << a[(int)a.size()-1] << endl;
}

int main(){
	IO_OP
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
