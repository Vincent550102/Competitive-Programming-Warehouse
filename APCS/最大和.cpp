#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	int s = 0;
	cin >> n >> m;
	vector<int> v;
	bool ok = true;
	for(int i =0; i<n; i++){
		int max_n = 0;
		for(int j = 0; j<m; j++){
			int tmp;
			cin >> tmp;
			max_n = max(max_n,tmp);
		}
		v.push_back(max_n);
		s+=max_n;
	}
	cout << s << endl;
	
	for(int x:v){
		if(!(s%x)){
			cout << x << " ";
			ok = false;
		}
	}
	if(ok)cout << "-1";
	cout << endl;
	
} 
