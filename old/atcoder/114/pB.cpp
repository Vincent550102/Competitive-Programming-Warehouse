#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	int flag = false;
	for(int i = 1; i<=sqrt(N); i++){
		if(N%i == 0){
			int an = N/i;
			if(an>0 && an<=9 && i>0 && i<=9){
				flag = true;
			}
		}
	}
	if(flag) cout << "Yes";
	else cout << "No";
}
