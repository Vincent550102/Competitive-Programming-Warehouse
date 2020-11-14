#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int mxX = 1e3+5;
const int mxY = 1e3+5;
int x,y;
int Sx,Sy,Ex,Ey;
int dr[4] = {1,2,-1,-2};
int dc[4] = {2,1,-2,-1};
bool flag = false;
bool visit[mxX][mxY];
#define _ <<" "<<
int ans = 1e6;

int main(){
	io_op
	cin >> x >> y;
	for(int i = 0; i<x; i++){
		for(int j = 0; j<y; j++){
			visit[i][j] = 0;
		}
	}
	cin >> Sx >> Sy >> Ex >> Ey;
	queue<pair<int,int> > Q;
	int ans = -1;
	bool ok = true;
	Q.push({Sx,Sy});
	visit[Sx][Sy]=1;
	while(ok){
		vector<pair<int,int> > buf;
		while(!Q.empty()){
			if(Q.front().F==Ex&&Q.front().S==Ey){
				ok=false;
				break;
			}
			for(int i = 0; i<4; i++){
				for(int j = 0; j<4; j++){
					if(abs(dr[i])!=abs(dc[j])){
//						cout << dr[i] _ dc[j] << endl;
						int nr=Q.front().F+dr[i];
						int nc=Q.front().S+dc[j];
						if(nr>=0&&nr<x&&nc>=0&&nc<y&&!visit[nr][nc]){
							visit[nr][nc] = 1;
							buf.emplace_back(make_pair(nr,nc));
						}
					}
				}
			}
//			cout << Q.front().F _ Q.front().S << endl;
			Q.pop();
		}
		for(auto x:buf){
			Q.push(x);
		}
		if(Q.empty()&&ok){
			ans = -1;
			break;
		}
		ans++;
	}
	
	cout << ans << endl;
}
