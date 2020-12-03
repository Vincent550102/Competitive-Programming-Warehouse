#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	vector<int> road{1,2,3};
	while(next_permutation(road.begin(),road.end())){
		for(int i = 0; i<3; i++)
			cout << road[i] <<" ";	
		cout << endl;
	}
}
