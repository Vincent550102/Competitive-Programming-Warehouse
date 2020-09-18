#include<bits/stdc++.h>
#define INF 1000000
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i<n-1; i++){
		int a,b;
		cin >> a >> b;
	}
	vector<int> ghost(m);
	int min_ans = INF;
	for(int i = 0; i<m; i++){
		cin >> ghost[i];
	}
	int pos;cin >> pos;
	for(int x:ghost){
		min_ans = min(min_ans,abs(pos-x));
	}
	cout << min_ans << endl;
	
}
