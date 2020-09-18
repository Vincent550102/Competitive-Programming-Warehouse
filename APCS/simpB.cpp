#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> lg;
int a,b,c,d;
int battle(char x, char y){
	if(x==y)return 2;
	if(x=='R'){
		if(y=='S')return 1;
		else return 0;
	}else if(x=='P'){
		if(y=='R')return 1;
		else return 0;
	}else{
		if(y=='P')return 1;
		else return 0;
	}
}
bool is_ok(int g){
	int len = lg.size();
	for(int i = len-1; i>=len-k;i--){
		if(lg[i]!=g)return 0;
	}
	return 1;
}
int point_x(int s){
	if(s==2)return b;
	if(s==1)return a;
	if(is_ok(s))return d;
	else return c;
}

int point_y(int s){
	if(s==2)return b;
	if(s==0)return a;
	if(is_ok(s))return d;
	else return c;
}

int main(){
	cin >> n >> k;
	cin >> a >> b >> c >> d;
	string X,Y;
	cin >> X >> Y;
	int score_X = 0;
	int score_Y = 0;
	for(int i = 0; i<n; i++){
		int result = battle(X[i],Y[i]);
		lg.push_back(result);
		score_X += point_x(result);
		score_Y += point_y(result);
	}
	cout << score_X << " " << score_Y << endl;
	
}
