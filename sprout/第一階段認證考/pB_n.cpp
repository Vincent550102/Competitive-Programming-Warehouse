#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >> t;while(t--){	
		int n,x,y,z;
		cin >> n >> x >> y >> z;
		vector<int> ele(n);
		vector<int> requr(n);
		for(int i = 0; i<n; i++)cin >> ele[i];
		for(int i = 0; i<n; i++)cin >> requr[i];
		if(n==x || n==y){
			bool flag1 = true;
			bool flag2 = true;
			for(int i = 0; i<n; i++){
				if(ele[i]!=requr[i]){
					flag1 = false;
				}
			}
			reverse(requr.begin(),requr.end());
			for(int i = 0; i<n; i++){
				if(ele[i]!=requr[i]){
					flag2 = false;
				}
			}
			if(flag1||flag2)cout << "Yes";
			else cout << "No";
		}else if(n==z){
			cout << "Yes";
		}
		cout << endl;
	}
}
