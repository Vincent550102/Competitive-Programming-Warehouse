#include<bits/stdc++.h>
using namespace std;
int n,t,p,q;
int instan_move_pos[10000] = {};
int smallest_move_time = 1000000;
int can_get = false;
void walk(int pos,int move_time){
	if(pos == t){
		smallest_move_time = min(smallest_move_time,move_time);
		can_get = true;
		return;
	}
	if(pos+p<n)walk(instan_move_pos[pos+p],move_time+1);
	if(pos-q>0)walk(instan_move_pos[pos-q],move_time+1);
}

int main(){
	cin >> n >> t >> p >> q;
	for(int i = 0; i<n; i++){
		cin >> instan_move_pos[i];
	}
	walk(0,0);
	if(!can_get) cout << "-1";
	else cout << smallest_move_time;
	
}

