#pragma GCC optimize("O3,unroll-loops")
#pragma loop_opt(on)

#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
#define endl '\n'
#define _ <<" "<<
using ll = long long;
//#define int ll 
constexpr ll MOD = 1e9+7;
using namespace std;
constexpr int mxN = 1e3+5;
int N,M,Q;
vector<pii> Q_cnt;
int G[mxN][mxN];

bool vaild(int r,int c){
	if(r>=0&&c>=0&&r<N&&c<M)return 1;
	return 0;
}

bool comp(pii a,pii b){
	if(a.F==b.F)return a.S<b.S;
	else return a.F<b.F;
}

vector<pii> cnt;

void Qfind(int r,int c){
	
	int nr = r;
	int nc = c+1;
	while(vaild(nr,nc)){
		if(G[nr][nc]){
			G[nr][nc]=0;
			cnt.push_back({nr,nc});
		}
		nc++;
	}
	nr = r+1;
	nc = c;
	while(vaild(nr,nc)){
		if(G[nr][nc]){
			G[nr][nc]=0;
			cnt.push_back({nr,nc});
		}
		nr++;
	}
	
	nr = r-1;
	nc = c;
	while(vaild(nr,nc)){
		if(G[nr][nc]){
			G[nr][nc]=0;
			cnt.push_back({nr,nc});
		}
		nr--;
	}
	
	nr = r;
	nc = c-1;
	while(vaild(nr,nc)){
		if(G[nr][nc]){
			G[nr][nc]=0;
			cnt.push_back({nr,nc});
		}
		nc--;
	}
	
	nr = r+1;
	nc = c+1;
	while(vaild(nr,nc)){
		if(G[nr][nc]){
			G[nr][nc]=0;
			cnt.push_back({nr,nc});
		}
		nr++;
		nc++;
	}
	nr = r+1;
	nc = c-1;
	while(vaild(nr,nc)){
		if(G[nr][nc]){
			G[nr][nc]=0;
			cnt.push_back({nr,nc});
		}
		nr++;
		nc--;
	}
	nr = r-1;
	nc = c+1;
	while(vaild(nr,nc)){
		if(G[nr][nc]){
			G[nr][nc]=0;
			cnt.push_back({nr,nc});
		}
		nr--;
		nc++;
	}
	nr = r-1;
	nc = c-1;
	while(vaild(nr,nc)){
		if(G[nr][nc]){
			cnt.push_back({nr,nc});
			G[nr][nc]=0;
		}
		nr--;
		nc--;
	}
}

signed main(){
	io_op
	cin >> N >> M >> Q;
	Q_cnt.resize(Q);
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			G[i][j]=0;
		}
	}
	for(int i = 0; i<Q; i++){
		cin >> Q_cnt[i].F >> Q_cnt[i].S;
		G[Q_cnt[i].F][Q_cnt[i].S]=1;
	}
	for(int i = 0; i<Q; i++){
		Qfind(Q_cnt[i].F,Q_cnt[i].S);
	}
	sort(cnt.begin(),cnt.end(),comp);
	if(cnt.size())cout << cnt.size() << endl;
	cout <<(!(int)cnt.size()?"-1\n":"");
	for(auto x:cnt){
		cout << x.F << " " << x.S << endl;
	}
}
