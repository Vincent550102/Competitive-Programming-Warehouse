#include<bits/stdc++.h>
using namespace std;
int N;
char G[105][105];
bool check[105][105];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

struct no{
	int x,y,c;
};

int main(){
	while(cin >> N&&N){
		int K_pos_r;
		int K_pos_c;
		queue<no> q;
		for(int i = 0; i<N; i++){
			cin >> G[i];
			int len = strlen(G[i]);
			for(int j = 0; j<len; j++){
				check[i][j] = false;
				if(G[i][j]=='K'){
					check[i][j] = true;
					q.push((no){i,j,0});
				}
			}
		}
		
		int ans =-1;
		while(!q.empty()){
			bool flag = true;
            int x=q.front().x,y=q.front().y,c=q.front().c;
            q.pop();
//			cout << endl;
            for(int i=0;i<4;i++){
            	int nr = x + dr[i];
            	int nc = y + dc[i];
                if(!(check[nr][nc])){
                	check[nr][nc] = true;
                    if(G[nr][nc]=='#')continue;
                    if(G[nr][nc]=='@'){
                        ans = c+1;
                        flag = false;
                        break;
                    }
                    if(G[nr][nc]=='.')q.push((no){nr,nc,c+1});
                }
            }
            if(!flag)break;
        }
        
		if(ans == -1){
			cout << "= =\"";
		}else{
			cout << ans;
		}
		cout << endl;
	}
}
