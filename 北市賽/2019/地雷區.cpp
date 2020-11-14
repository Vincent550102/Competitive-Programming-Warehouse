#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define F first
#define S second

constexpr int dr[24] = {0,0,1,-1,1,1,-1,-1,2,2,2,2,2,-2,-2,-2,-2,-2,1,0,-1,1,0,-1};
constexpr int dc[24] = {1,-1,0,0,-1,1,-1,1,0,1,2,-1,-2,0,1,2,-1,-2,2,2,2,-2,-2,-2};
constexpr int mxN = 5e5+5;
int c;
struct DJS{
	int f[mxN];
	void init(){for(int i = 0; i<=mxN; i++)f[i]=i;}
	int query(int x){return  f[x]==x?x:f[x]=query(f[x]);}
	void unite(int a,int b){
		a=query(a);b=query(b);
		f[a]=b;
	}
	int count(){
		int cnt = 0;
		for(int i = 1; i<=c; i++){
			f[i] = query(i);
		}
//		vector<bool> ok(c+1,0);	
		for(int i = 1; i<=c; i++){
			if(f[i]==i)cnt++;
		}
		return cnt;
	}
	
};
int a,b;

bool vaild(int r,int c){
	return (min(r,c)>=1&&r<=a&&c<=b);
}

int main(){
	DJS djs;
	djs.init();
	cin >> a>> b >> c;
	map<pii,int> MP;
	for(int i = 0; i<c; i++){
		int r,c;
		cin >> r >> c;
		MP[{r,c}]=i+1;
	}
	for(auto x:MP){
		for(int j = 0; j<24; j++){
			int nr = x.F.F+dr[j];
			int nc = x.F.S+dc[j];
			if(vaild(nr,nc)&&MP.count({nr,nc})){
				djs.unite(x.S,MP[{nr,nc}]);
			}
		}
	}
	cout << djs.count() << endl;
	
}
