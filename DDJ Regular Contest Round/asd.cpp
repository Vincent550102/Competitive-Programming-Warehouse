#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin >> n){
		int num, prenum,sum = 0;
		for(int i = 0; i<n; i++){
			cin >> num;
			sum += i?abs(num-prenum):0;
			prenum = num;
		}
		cout << (sum==(n*n-n)/2?"Jolly\n":"Not jolly\n");
	}
}
