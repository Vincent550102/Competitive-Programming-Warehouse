#include<bits/stdc++.h>
#define INF 0xffffff
using namespace std;
int main(){
	int case_num;
	cin >> case_num;
	while(case_num--){
		int r;
		cin >> r;
		int name_board[505];
		for(int i = 0; i<r; i++){
			cin >> name_board[i];
		}
		int min_board_num = INF;
		for(int i = 0; i<r; i++){
			int num = 0;
			for(int j = 0; j<r; j++){
				num += abs(name_board[i]-name_board[j]);
			}
			min_board_num = min(min_board_num,num);
		}
		cout << min_board_num << endl;
	}
	
}
