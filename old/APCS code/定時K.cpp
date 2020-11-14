#include<bits/stdc++.h>
using namespace std;
int f(int N,int M, int K){
	if(K == 0)return 0;
	return (M+f(N-1,M,K-1))%N;
}
int main(){
	int N,M,K;
	cin >> N >> M >>K;
	cout << 1+f(N,M,K) <<'\n';
}
