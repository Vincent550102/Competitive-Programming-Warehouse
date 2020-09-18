#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > suDoKu;
vector<int> tmp;

bool ChechNum(const int num, bool used[9]) {              
	if (num == -1) return true;
	if (used[num - 1]) return false;
	else {
		used[num - 1] = true;
		return true;
	}
}

bool IsSudoValid(vector<vector<int>>& board) {
	bool used[9];
	for (int i = 0; i < 9; ++i) {
		fill(used, used + 9, false);                 
		for (int j = 0; j < 9; ++j) {                
			if (!ChechNum(board[i][j], used))
				return false;
		}
		fill(used, used + 9, false);
		for (int j = 0; j < 9; ++j) {               
			if (!ChechNum(board[j][i], used))
				return false;
		}
	}
	for(int r=0;r<3;++r)                             
		for (int c = 0; c < 3; ++c) {                
			fill(used, used + 9, false);
			for (int i = 3 * r; i < r * 3+3; ++i)
				for (int j = 3 * c; j < c * 3+3; ++j)
					if (!ChechNum(board[i][j], used))
						return false;
		}
	return true;
}

bool isVliad(vector<vector<int>>& board, int x, int y) {
	for (int row = 0; row < 9; ++row) {                        
		if (row != x && board[row][y] == board[x][y])
			return false;
	}
	for (int col = 0; col < 9; ++col) {                       
		if (col != y && board[x][col] == board[x][y])
			return false;
	}
	for (int row = 3 * (x / 3); row < 3 * (x / 3 + 1); ++row)
		for (int col = 3 * (y / 3); col < 3 * (y / 3 + 1); ++col)
			if ((row != x || col != y) && board[row][col] == board[x][y])
				return false;
	return true;
}

bool solveSudoKu(vector<vector<int>>& sudo) {
	for (int row = 0;row < 9; ++row) 
		for (int col = 0; col < 9; ++col) {
			if (sudo[row][col] == -1) {
				for (int i = 1; i < 10; ++i) {
					sudo[row][col] = i;
					if (isVliad(sudo,row,col) && solveSudoKu(sudo))
						return true;
					sudo[row][col] = -1;
				}
				return false;
			}
		}
	return true;
}

int main(){
	string str;
	while(cin >> str&&str!="end"){
		for(int i = 0; i<9; i++){
			tmp.resize(9,-1);
			for(int j = 0; j<9; j++){
				tmp[j] = (str[i*9+j] == '.')? -1 : str[i*9+j]-'0';
			}
			suDoKu.emplace_back(tmp);
			tmp.clear();
		}
		solveSudoKu(suDoKu);
		bool flag = true;
		for (auto vec : suDoKu) {
			for (auto value : vec)
				if(value==-1)flag = false;
		}
		if(!IsSudoValid(suDoKu)||!flag){
			cout << "No solution.\n";
		}else{
			for (auto vec : suDoKu) {
				for (auto value : vec)
					cout << value;
			}
			cout << endl;
		}
		suDoKu.clear();
	}
}
