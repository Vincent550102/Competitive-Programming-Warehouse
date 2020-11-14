#include<bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		bool round = true;
		int arr[205];
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			arr[i]--;
		}
		
		for(int i = 1; i<n; i++){
			if(arr[i] != (arr[i-1] + 1) % n){
				round = false;
				break;
			}
		}
		round = round && arr[0] == (arr[n-1] + 1) % n;
		
		if(round){
			cout << "YES" << endl;
			continue;
		}
		round = true;
		for(int i = 1; i<n; i++){
			if(arr[i] != (arr[i-1]+n-1)%n){
				round = false;
				break;
			}
		}
		round = round && arr[0] == (arr[n-1]+n-1) % n;
		
		if(round) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
}
