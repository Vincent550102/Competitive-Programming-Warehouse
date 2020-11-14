#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int,int>num_set;
	num_set[3]++;
	num_set[4]++;
	num_set[1]++;
	num_set[1]++;
	for(auto x:num_set){
		cout << x.first;
	}
} 
