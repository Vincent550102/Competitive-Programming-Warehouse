#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,K;
int P[5000001];

bool test(int x){
	int count = 0;
	int next;
	for(int i = 0; i<N;){
		next = P[i] + x;
		count ++;
		if(count > K) return false;
		if(next >= P[N-1] && count <= K) return true;
		do{
			i++;
		}while(P[i] <= next);
	}
	return false;
}

int main(){
	cin.tie(0);
	while(cin>>N){
		cin >> K;
		for(int i = 0; i<N; i++){
			cin >> P[i];
		}	
		sort(P,P+N);
		if(K == 1){
			cout << P[N-1] - P[0] << endl;
		}else{
			int l = 1;
			int r = ((P[N-1] - P[0]) / K) + 1;
			int m;
			while(l <= r){
				m = (l+r)/2; 
				if(test(m)) r = m;
				else l = m+1;
				if(l == r) break;
			}
			cout << r << endl;
			
		}
	}
}
