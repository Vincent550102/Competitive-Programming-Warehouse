#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> v(n);
	int max_n=0;
	for(int i = 0; i<n; i++){
		cin >> v[i];
		max_n = max(max_n,v[i]);
	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(m<v[i]&&k>1){
			k--;
			m=v[i];
		}else if(m<v[i]&&k==1){
			k--;
			m=max_n;
		}
//		cout << m << " ";
		ans+=m;
	}
	cout << ans << endl;
}
