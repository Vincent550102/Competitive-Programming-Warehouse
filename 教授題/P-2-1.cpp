#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	set<int> S;
	for(int i = 0; i<n; i++){
		int tmp;cin >> tmp;
		S.insert(tmp);
	}
	cout << S.size() << endl;
	for(int x:S){
		cout << x << " ";
	}
}
