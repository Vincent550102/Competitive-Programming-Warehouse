#include<bits/stdc++.h>
const int eps = -1e9;
using namespace std;
bool operator==(const double &a,const double &b){
	return b-eps<a&&a<b+eps;
}
//int *a -> *;
int main(){
	int n;
	cin >> n;
	vector<double> v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i];
	}
	int cnt = 0;
	for(int k = 0; k<n; k++){
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				cout << i << " " << j << " " << k << endl;
				if((v[i]+v[j]) == v[k]){
					cnt++;	
				}
			}
		}
	}
	cout << cnt << endl;
}
