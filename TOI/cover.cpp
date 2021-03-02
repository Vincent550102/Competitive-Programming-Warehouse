#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using pii = pair<int,int>;
constexpr int mxN = 3e3+5;
#define F first
#define S second
#define All(x) x.begin(),x.end()
#define _ <<" "<<
int n,l,w;

int ano_slide(vector<pii> G, int L, int R){
	//range int G->(L,R)
	sort(G.begin()+L, G.begin()+R+1, [](pii a, pii b) -> bool{
		return a.S<b.S;
	});
	int rb = L;
	int ans = -1;
	int cnt = 1;
	for(int lb = L; lb<=R; lb++ ,cnt--){
		int nxt = G[lb].S+l;
		while(rb+1<=R and G[rb+1].S<=nxt){
			cnt++;
			rb++;
		}
//		cout << L _ R _ lb _ rb _ cnt _ nxt<< endl;
		ans = max(ans, cnt);
	}
	return ans;
}

int main(){
	vector<pii> G;
	cin >> n;
	cin >> l >> w;
	G.resize(n);
	for(int i = 0; i<n; i++){
		cin >> G[i].F >> G[i].S;
	}
	
	sort(All(G), [](pii a, pii b){
		if(a.F==b.F)return a.S<b.S;
		else return a.F<b.F;
	});
//	cout << "---\n";
//	for(auto x:G){
//		cout << x.F _ x.S << endl;
//	}
//	cout << "---\n";
	int ans = -1;
	int R = 0;
	for(int L = 0; L<n; L++){
		int nxt = G[L].F+w;
		while(R+1<n && G[R+1].F <= nxt){
			R++;
		}
		
//		cout << L _ R _ G[L].F _ w _ nxt<< endl;
		ans = max(ans, ano_slide(G,L,R));
	}
	cout << ans << endl;
}
