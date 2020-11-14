#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main(){
	int n,m;
	ll map[105][105];
	bool check_map[105][105];
	int dir_r[4] = {-1,0,1,0};
	int dir_c[4] = {0,1,0,-1};
	cin >> n >> m;
	int min_point_r = -1,min_point_c = -1;
	int min_point_value = 1000005;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> map[i][j];
			if(min_point_value > map[i][j]){
				min_point_value = map[i][j];
				min_point_r = i;
				min_point_c = j;
			}
		}
	}
	ll sum = 0;
	int now_r = min_point_r , now_c = min_point_c;
	check_map[now_r][now_c] = true;
	sum += map[now_r][now_c];
	while(1){
		int most_low_r = -1,most_low_c = -1;
		int most_low_value= 1000005;
		bool flag = true;
		for(int i = 0; i<4; i++){
			int next_r = now_r+dir_r[i];
			int next_c = now_c+dir_c[i];
			if(next_r<n  &&next_r >= 0&& next_c <m && next_c >= 0){
				if(check_map[next_r][next_c] != true){
					if(most_low_value > map[next_r][next_c]){
						flag = false;
						most_low_value = map[next_r][next_c];
						most_low_r = next_r;
						most_low_c = next_c;
					}
				}
			}
			
		}
		if(flag) break;
		sum += map[most_low_r][most_low_c];
		check_map[most_low_r][most_low_c] = true;
		now_r = most_low_r;
		now_c = most_low_c;
	}
	cout << sum << endl;
} 
