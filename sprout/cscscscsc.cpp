#include<bits/stdc++.h>
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main(){
	unordered_map<int,int> M;
	srand(chrono::steady_clock::now().time_since_epoch().count());
//	cout << rng;
	M.insert({8,rand()});
	cout << M[8];
}
