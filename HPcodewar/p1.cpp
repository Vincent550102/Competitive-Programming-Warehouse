#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

bool is_prime(int x){
	for(int i = 2; i<=sqrt(x); i++){
		if(x%i==0)return 0;
	}
	return 1;
}

int main(){
	string str;
	cin >> str;
	int one = stoi(str);
	reverse(str.begin(),str.end());
	int two = stoi(str);
	if(is_prime(one)&&is_prime(two))cout << "IS VIP";
	else cout << "NOT VIP";
	cout << endl;
}
