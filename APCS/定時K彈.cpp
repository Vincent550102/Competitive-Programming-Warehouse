#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> v(n);
	for(int i = 0; i<n; i++){
		v[i] = i;
	}
	int now = 0;
	while(k--){	
//		cout << now << " " << v[now];
		now += m-1;
		now %= v.size();
		v.erase(v.begin()+now);
	}
	now%=v.size();
	cout << v[now]+1 << endl;
}
