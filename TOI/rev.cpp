#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define lb(x) x&-x;
#define int long long
int n;
struct BIT{
	vector<int> v;
	void modify(int x, int d){
		while(x<=n){
			v[x]+=d;
			x+=lb(x);
		}
	}
	int query(int x){
		int resul = 0;
		while(x){
			resul += v[x];
			x-=lb(x);
		}
		return resul;
	}
}bit;

signed main(){
	io_op
	cin >> n;
//	BIT bit;
	bit.v.resize(n+1,0);
	vector<pair<int,int> > ele(n);
	#define F first
	#define S second
	for(int i = 0; i<n; i++){
		cin >> ele[i].F;
		ele[i].S=i;
	}
	#define All(x) x.begin(),x.end()
	sort(All(ele),[](pair<int,int> a, pair<int,int> b) -> bool{
		return a.F==b.F?a.S<b.S:a.F<b.F;
	});
	int ans = 0;
	for(int i = 0; i<n; i++){
		ans+=i-bit.query(ele[i].S+1);
		bit.modify(ele[i].S+1,1);
	}
	cout << ans << endl;
}
