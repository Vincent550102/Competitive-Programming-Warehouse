#include<bits/stdc++.h>

#define ll long long int

int move_one(int a){
	return a-1;
}

int move_two(int a){
	return a/10;	
}

using namespace std;
int main(){
	ll N;
	int K;
	cin >> N >> K;
	while(K--){
		if(N%10)
			N = move_one(N);
		else
			N = move_two(N);
	}	
	
	cout << N;
}
