#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> v = {9,8,7,6,5,4,3,2,1};
	int L = 3;
	int R = 5;
	sort(v.begin()+L,v.begin()+R+1);
	for(int x:v){
		cout << x << " ";
	}
	cout << endl;
	for(int i = 0; i<10; i++){
		cout << i << " ";
	}
}
