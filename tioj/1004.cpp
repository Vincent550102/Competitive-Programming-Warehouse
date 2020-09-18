#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i<n; i++){
		v[i] = i;
	}
	int now = 0;
	while(v.size()!=1){
		now+=2;
		now--;
		now%=v.size();
//		cout << now;
		v.erase(v.begin()+now);
	}
	cout << v[0]+1 << endl;
}
