#include<bits/stdc++.h>
using namespace std;
int main(){
	int case_num;
	cin >> case_num;
	while(case_num--){
		int a,b,n,S;
		cin >> a >> b >> n >> S;
		if(S/n <= a){
			if(b>=S%n){
				cout <<"Yes";
			}else{
				cout << "No";
			}
		}else{
			if(S-(n*a) > b){
				cout << "No";
			}else{
				cout << "Yes";
			}
		}
		cout <<'\n';
	}
}
