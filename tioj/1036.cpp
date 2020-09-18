#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e7+5;
bool sieve[mxN];

void build(){
	vector<int> prime;
	for(int i = 2; i<mxN; i++){
		if (!sieve[i]) prime.push_back(i);
        for (int j=0; j<(int)prime.size()&&prime[j]<=mxN/i; j++){
            sieve[i*prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
	}
	prime.clear();
} 

int main(){
	fill(sieve,sieve+mxN,0);
	build();
	int m,n;
	cin >> m;
	while(m--){
		cin >> n;
		int cnt = 0;
		for(int i = 2; i<=n; i++){
			if(!sieve[i])cnt++;
		}
		cout << cnt << endl;
	}
}
