#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int &x:v){
		cin >> x;
	}
	sort(v.begin(),v.end());
	bool flag = true;
	for(int i = 0; i<n; i++){
		if(v[i]!=i+1)flag = false;
	}
	cout << (flag?"Yes":"No") << endl;
}
