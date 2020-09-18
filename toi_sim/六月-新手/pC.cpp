#include<bits/stdc++.h>
#define mxN 20
using namespace std;
int arr[mxN][mxN];
int r,c;
int ans1 = 0,ans2 = 0;
void dfs1(int x,int y){
	for(int i = -1; i<=1; i++){
		for(int j = -1; j<=1; j++){
			if((i==j)||x+i<0||y+j<0||x+i>r||y+j>c)continue;
			if(arr[x+i][y+j]==5){
				arr[x][y]=0;
				arr[x+i][y+j]=0;
			}
		}
	}
}

void dfs2(int x,int y){
	for(int i = -1; i<=1; i++){
		for(int j = -1; j<=1; j++){
			if((i==j)||x+i<0||y+j<0||x+i>r||y+j>c)continue;
			if(arr[x+i][y+j]==1){
				arr[x+i][y+j]=7;
				ans1++;
			}
		}
	}
}

int main(){
//	int r,c;
	cin >> r >> c;
	for(int i =0 ; i<r; i++){
		for(int j = 0;j<c; j++){
			cin >> arr[i][j];
		}
	}
	for(int i =0 ; i<r; i++){
		for(int j = 0;j<c; j++){
			if(arr[i][j]==5)dfs1(i,j);
		}
	}
//	cerr << " d";
	for(int i =0 ; i<r; i++){
		for(int j = 0;j<c; j++){
			if(arr[i][j]==5)dfs2(i,j);
		}
	}
//	int ans1=0,ans2=0;
	cout << endl;
	for(int i =0 ; i<r; i++){
		for(int j = 0;j<c; j++){
			cout << arr[i][j] << " ";
			if(arr[i][j]==1)ans2++;
		}
		cout << endl;
	}
	cout << ans1 << " " << ans2 << endl;
}
