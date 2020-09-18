#include<bits/stdc++.h>

#define F first
#define S second
#define pii pair<int,int>
using namespace std;
bool cmp(pii a,pii b){
	if(a.S!=b.S)return a.S>b.S;
	else return a.F<b.F;
}
int main(){
	int n;
	while(cin >> n&&n){
		vector<pii> cust;
		int cnt = n;
		while(cnt--){
			int a,b;cin >> a >> b;
			cust.emplace_back(make_pair(a,b));
		}
		sort(cust.begin(),cust.end(),cmp);
		int cook = 0;
		int ans = 0;
		for(int i = 0; i<n; i++){
			cook+=cust[i].F;
			
			ans = max(cook+cust[i].S,ans);
		}
		cout << ans << endl;
	}
	
}
