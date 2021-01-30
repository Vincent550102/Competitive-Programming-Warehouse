#include<iostream>
#include<algorithm>
using namespace std;
const int mxN = 50005;

int p[3*mxN];
struct DSU{
	void init(int n){
		for(int i = 1; i<=n; i++){
			p[i]=i;	
		}
	}
	int query(int x){
		return p[x]==x?x:p[x]=query(x);
	}
	void Merge(int a,int b){
		p[query(a)]=query(b);
	}
}dsu;

int trs(int a,int b){
	return 3*a-b;
}

int main(){
//	DSU dsu;
//	freopen("in.txt","r",stdin);
	int n,k;cin >> n >> k;
	dsu.init(4*n);
	int ans = 0;
	while(k--){
		int d,x,y;
		cin >> d >> x >> y;
//		cerr <<"d";
		if(max(x,y)>n){
			ans++;
			continue;
		}
		// 0->A
		// 1->B
		// 2->C
		if(d==1){
			#define _ <<" "<<
			if(dsu.query(trs(x,0))==dsu.query(trs(y,1))||dsu.query(trs(x,0))==dsu.query(trs(y,2))){
				ans++; //conf
				continue;
			}
//			cerr << "d" _ x _ y << endl;
			for(int i = 0; i<3; i++){
				dsu.Merge( trs(x,i),trs(y,i) );
			}
		}else if(d==2){
			if(dsu.query(trs(x,0))==dsu.query(trs(y,0))||dsu.query(trs(x,0))==dsu.query(trs(y,2))){
				ans++; //conf
				continue;
			}
			for(int i = 0; i<3; i++){
				dsu.Merge(trs(x,i),trs(y,(i+1)%3));
			}
		}
	}
	cout << ans << endl;
}
