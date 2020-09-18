#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int mxN = 5005;

bool prime[mxN+5];

void build(){
	fill(prime,prime+mxN,1);
	prime[1]=0;
	for(int i = 2; i <mxN; i++){
		if(prime[i]){
			for(int j = 2*i; j<mxN; j+=i){
				prime[j]= 0;
			}
		}
	}
//	cout <<"d";
}

int main(){
//	io_op
	build();
	int n;
//	cout << 'd';
	while(cin >> n){
//		cout << "d";
		cout << "primes between 1 ~ "<< n <<":";
		for(int i = 1; i<=n; i++){
			if(prime[i])cout<<" " << i;
		}
		cout << '\n';
	}
	
} 
