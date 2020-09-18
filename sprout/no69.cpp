#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cerr<<#x<<" is "<<x << endl
using namespace std;
using ll=long long;
#define int ll

vector<pair<int,int> > my_horse;
vector<int> comp;
int n,k;

bool check(int M){
	vector<int> v(n+1);
	for (int i=1;i<=n;++i)
		v[i] = my_horse[i].first + (M*my_horse[i].second);
	sort(v.begin()+1,v.end());
	int j=1,get=0;
	for (int i=1;i<=n;++i){
		while (v[j]<=comp[i]){
			++j;
			if (j>n) break;
		}
		
		if (j>n) break;
		++get;
		++j;
		if (get>=k) return true;
	}
	v.clear();
	return false;
}


 main(){
	FAST
	int t;cin >> t;while(t--){
		cin >> n >> k;
		my_horse.resize(n+1);
		comp.resize(n+1);
		
		for(int i = 1; i<=n; i++){
			int a,b;cin >> a >> b;
			my_horse[i] = make_pair(a,b);
		}
		
		for(int i = 1; i<=n; i++){
			cin >> comp[i];
		}
		sort(comp.begin()+1,comp.end());
		if (!check(100000000)){
			cout << "-1\n";
		}else{
			int ans = 100000000;
			int l= 0,r = ans;
			while (l<=r){
				int mid=(l+r)>>1;
				if (check(mid)){
					if (ans>mid) ans=mid;
					r=mid-1;
				}else
					l=mid+1;
			}
			cout<<ans<<endl;
		}
		my_horse.clear();
		comp.clear();
	}
	return 0;
}
