#include<bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin >> q;
	while(q--){
		vector<long long> vec;
		vec.resize(5);
		long long sum = 0;
		for(int i = 0; i<3; i++){
			cin >> vec[i];
			sum+=vec[i];
		}
		cout << sum/2 << '\n';
	}
}
