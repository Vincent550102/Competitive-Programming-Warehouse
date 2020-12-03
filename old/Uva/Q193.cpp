#include<bits/stdc++.h>
using namespace std;

int max_black = -1;
int n;
int color[1000],checked[1000];
int adj_martex[1000][1000];

void dfs(int point,int edge,int black{
	if(edge == max_edge){
		max_black = max(max_black,black);
		return;
	}
	
}

int main(){
	int case_num;
	
	cin >> case_num;
	while(case_num--){
		int n,k;
		cin >> n >> k;
		
		for(int i = 0; i< k; i++){
			int a,b;
			cin >> a >> b;
			adj_martex[a][b] = adj_martex[b][a] = 1;
		}
		
	}
} 
