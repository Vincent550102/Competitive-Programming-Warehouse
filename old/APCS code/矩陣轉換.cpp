#include<bits/stdc++.h>
using namespace std;

int a[100][100],b[100][100];

void right_row(int R,int C){
	int x = -1,y = -1;
	for(int i = 0; i<C; i++){
		x++;
		y=-1;
		for(int j = R-1; j>=0; j--){
			y++;
			b[x][y]=a[j][i];
		}
	}
	swap(R,C);
	for(int i = 0; i<R; i++){
		for(int j = 0; j<C; j++){
			a[i][j] = b[i][j];
		}
	}
	
}

void reverse(int R,int C){
	int x = -1,y = -1;
	for(int i = R-1; i>=0; i--){
		x++;
		y=-1;
		for(int j = 0; j<C; j++){
			y++;
			b[x][y]=a[i][j];
		}
	}
	for(int i = 0; i<R; i++){
		for(int j = 0; j<C; j++){
			a[i][j] = b[i][j];
		}
	}
} 

int main(){

	
//	吃資料 //	清空
	int R,C,M;
	while(cin >> R >> C >> M){
		for(int i = 0; i<R; i++){
			for(int j = 0; j<C; j++){
				cin >> a[i][j];
			}
		} 
//		操作	
		for(int i = 0; i<M; i++){
			int comm;
			cin >> comm;
			if(comm == 1){
				reverse(R,C);
				
			}else if(comm == 0){
				right_row(R,C);
				int tmp;
				tmp = R;
				R = C;
				C = tmp;
			}
		}
		
		
//		印出來 
		for(int i = 0; i<R; i++){
			for(int j = 0; j<C; j++){
				cout << a[i][j];
			}
			cout << '\n';
		}
	}
}
