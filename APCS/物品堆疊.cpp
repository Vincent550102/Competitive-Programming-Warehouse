#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
bool cmp(pii a,pii b){
	return a.F*b.S<a.S*b.F;
}
int main(){
	int n;
	cin >> n;
	vector<pii> v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i].F;
	}
	for(int i = 0; i<n; i++){
		cin >> v[i].S;
	}
	sort(v.begin(),v.end(),cmp);
	long long cnt = v[0].F;
	long long ans = 0;
	for(int i = 1; i<n; i++){
		ans+=v[i].S*cnt;
		cnt+=v[i].F;
	}
	cout << ans << endl;	
}
