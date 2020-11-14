#include<bits/stdc++.h>
using namespace std;

vector<int > vis(106,0);
vector<int> tmp_adj(106,0);
vector<vector<int>> adjmetrix(106,tmp_adj);
vector<bool> black(106,0);

void dfs(int n, ){
	
}


int main(){
	int case_num;
	for(auto x:black){
		cout << x;
	}
	cin >> case_num;
	while(case_num--){
		int n,k;
		cin >> n >> k;
		for(int i = 0; i<k; i++){
			int l_p,r_p;
			cin >> l_p >> r_p;
			adjmetrix[l_p][r_p] = adjmetrix[r_p][l_p] = 1;
			vis[l_p] = vis[r_p] = 1;
		}
		
	}
	
	
}
