#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for(int i = 0; i<n; i++){
		cin >> v[i];
		sum+=v[i];
	}
	sort(v.begin(),v.end());
	
	if(sum%3||v[n-1] >sum/3)cout << "NO";
	else{
		for(int x:v)cout << x << ' ';
	}
}
