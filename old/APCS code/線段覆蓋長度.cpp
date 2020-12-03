#include<bits/stdc++.h>
using namespace std;
bool arr[10000005];
int main(){
	cin.tie(0);
	int N;
	
	int L,R;
	
	while(cin >> N){
		int MaxN = -1;
		for(int i =0; i<N; i++){
			cin >> L >> R;
			MaxN = max(max(L,R),MaxN);
			for(int i = L; i<R; i++){
				arr[i] = true;
			}
		}
		int counter = 0;
		for(int i = 0; i<MaxN; i++){
			if(arr[i] == true){
				counter++;
			}
		}
		cout << counter<<'\n';
	}
}
