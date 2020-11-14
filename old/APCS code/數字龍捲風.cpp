#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	int dir;
	
	int row_dir[] = {0,-1,0,1};
	int col_dir[] = {-1,0,1,0};
	
	bool check_mark[100][100];
	vector<vector<int> > map;
	
	cin >> N;
	cin >> dir;
	
	//0 -> left
	//1 -> up
	//2 -> right
	//3 -> down
	
	int way_time = N*N-1;
	
	for(int i = 0; i<N; i++){
		vector<int> tmp;
		for(int j = 0; j<N; j++){
			int Nu;
			cin >> Nu;
			tmp.emplace_back(Nu);
			check_mark[i][j] = false;
		}
		map.emplace_back(tmp);
	}
	
	int now_row = N/2, now_col = N/2;
	check_mark[now_row][now_col] = true;
	cout << map[now_row][now_col];
	while(way_time--){
		int next_dir = dir;
		int next_row = now_row + row_dir[next_dir];
		int next_col = now_col + col_dir[next_dir];
		while(check_mark[next_row][next_col] == true){	
			if(dir-1 == -1) dir = 3;
			else dir--;
			next_dir = dir;
			next_row = now_row + row_dir[next_dir];
			next_col = now_col + col_dir[next_dir];
		}
		cout << map[next_row][next_col];
		check_mark[next_row][next_col] = true;
		dir = next_dir+1;
		dir %= 4;
		now_row =  next_row;
		now_col =  next_col;
	}
	
	
}
