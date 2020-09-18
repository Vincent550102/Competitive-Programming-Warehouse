#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define X first
#define Y second
using ll = long long;
#define int ll
vector<PII> Pt;
int d(PII one,PII two){
	return (one.X-two.X)*(one.X-two.X)+(one.Y-two.Y)*(one.Y-two.Y);
}
signed main(){
	int n;
	cin >> n;
	Pt.resize(n);
	for(int i = 0; i<n; i++){
		int a,b;
		cin >> a >> b;
		Pt[i] = make_pair(a,b);
	}
	map<int,int>MP;
	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++){
			int dis = d(Pt[i],Pt[j]);
//			cout << dis << endl;
			if(!MP.count(dis)){
				MP[dis] = 1;
			}else{
				MP[dis]++;
			}
		}
	}
	int ans = 0;
	for(auto x:MP){
		if(x.second!=1){
			ans+=(x.second*(x.second-1))/2;
		}
	}
	cout << ans << endl;
}
