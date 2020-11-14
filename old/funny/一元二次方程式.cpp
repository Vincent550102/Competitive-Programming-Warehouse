#include<bits/stdc++.h>
using namespace std;
int main(){ 
	int a,b,c;
	int N;
	cin >> N;
	while(N--){
		cin >> a >> b >> c;
		auto ans = b*b - 4*a*c;
		if(ans>=0){
			cout << "Yes";
		}else{
			cout << "No";
		}
		cout << '\n';
	}
}
