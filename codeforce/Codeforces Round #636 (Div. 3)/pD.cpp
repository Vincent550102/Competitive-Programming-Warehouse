#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;while(t--){
		int n,k;
		cin >> n >> k;
		int ans = 0;
		vector<int>v(n);
		for(int i = 0; i<n; i++){
			cin >> v[i];
		}
		map<int,int> MP;
		int max_num = 1;
		for(int i = 0; i<n/2; i++){
			int sum = v[i]+v[n-i-1];
			if(!MP.count(sum)){
				MP[sum] = 1;
			}else{
				MP[sum]++;
			}
//			cout << sum << " " << MP[sum] << endl;
			max_num = max(max_num,MP[sum]);
//			cout << sum << " " << MP[sum] << endl;
		}
		cout << n/2 - max_num << endl;
	}
}
