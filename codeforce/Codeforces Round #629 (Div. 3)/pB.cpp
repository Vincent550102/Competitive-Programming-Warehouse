#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >> t;while(t--){
		int n,k;
		cin>>n >> k;
		int idx1=0,idx2=1;
		for(int i = 1; i<k; i++){
			if(idx1+1==idx2){
				idx1=0;
				idx2++;
			}else idx1++;
		}
		for(int i = n-1; i>=0; i--){
			if(i==idx1||i==idx2)cout << "b";
			else cout << "a";
		}
		cout << endl;
	}
}
