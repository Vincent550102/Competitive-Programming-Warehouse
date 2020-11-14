#include<bits/stdc++.h>

#define kvec vector<pair<char,int> > 

using namespace std;

bool cmp(pair<char,int> a, pair<char,int> b){
	if(a.second > b.second){
		return a>b;
	}else if(a.second == b.second){
		if(a.first > b.second){
			return a>b;
		}
	}else{
		return a<b;
	}
}

void dfs(char (*map_map)[1000],int r, int c){
	char point = map_map[r][c];
	map_map[r][c] = '.';
	int dirr[4] = {-1,1,0,0};
	int dirc[4] = {0,0,-1,1};
	for(int i = 0; i<4; i++){
		int n_r = r+dirr[i];
		int n_c = c+dirc[i];
		
		if(map_map[n_r][n_c] == point)
			dfs(map_map,n_r,n_c); 
	}
}

char map_map[1000][1000];

int main(){
	int N;
	cin >> N;
	for(int i = 1; i<= N; i++){
		int r,c;
		cin >> r >> c;
		kvec kind_count;
		for(int j = 0; j<r; j++){
			for(int k = 0; k<c; k++){
				cin >> map_map[j][k];
			}
		}
		
		for(int j = 0; j<r; j++){
			for(int k = 0; k<c; k++){
				if(map_map[j][k] != '.'){
					char point_n = map_map[j][k];
					dfs(map_map,j,k);
					bool flag = true;
					for(auto x:kind_count){
						if(point_n == x.first){
							flag = false;
							x.second += 1;
							cout << x.first << x.second;
						}
					}
					if(flag){
						
						kind_count.emplace_back(make_pair(point_n,1));	
					}
				}else{
					continue;
				}
			}
		}
		
		sort(kind_count.begin() , kind_count.end() ,cmp);
		cout << "World #" <<i << '\n';
		for(auto x:kind_count){
			cout << x.first <<": " << x.second << '\n';
		}
		
	}
}
