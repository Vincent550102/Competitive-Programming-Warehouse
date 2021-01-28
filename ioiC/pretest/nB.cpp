#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define Pb push_back
#define F first
#define S second

constexpr int N = 1e6 + 5;


vector<pair<int,pair<pair<int,int>,int> > > G;

struct Seg{
	struct Node{
		int len=0;
		int cnt=0;
	} arr[4*N];
	
	void pull(int id, int l, int r){
		if(arr[id].cnt) arr[id].len = r - l;
		else arr[id].len = (r - l)? (arr[id*2+1].len+arr[id*2+2].len) : 0;
	}
	void modify(int l, int r,int ql, int qr, int c, int id){
		if(r <= ql) return;
		if(qr <= l) return;
		if(ql <= l and r <= qr){
			arr[id].cnt+=c;
		}else{
			int m = (l+r)>>1;
			modify(l, m, ql, qr, c, id*2+1);
			modify(m, r, ql, qr, c, id*2+2);
		}
		pull(id, l, r);
	}
	void modify(int l, int r, int c){
		modify(0, N, l, r, c, 0);
	}
	long long query(){
		return arr[0].len;
	}
}seg;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int l, r, d, u;cin>>l>>r>>d>>u;
		G.Pb({l, {{d, u}, 1}});
		G.Pb({r, {{d, u}, -1}});
	}
	sort(ALL(G));
	int prev=0;
	long long ans=0;
	for(auto E:G){
		ans += seg.query() * (E.F - prev);
		seg.modify(E.S.F.F, E.S.F.S, E.S.S);
		prev = E.F;
	}
	cout<<ans<<'\n';
}
