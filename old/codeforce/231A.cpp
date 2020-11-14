#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	int sum = 0;
	vector<int>vec;
	vec.resize(5);
	cin >> N;
	while(N--){
		int counter = 0;
		for(int i =0; i<3; i++){
			cin>> vec[i];
			if(vec[i] == 1){
				counter++;
			}
		}
		if(counter>=2){
			sum++;
		}
	}
	cout << sum << endl;
}
