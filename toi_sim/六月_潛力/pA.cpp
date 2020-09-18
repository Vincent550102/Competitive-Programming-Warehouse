#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define F first
#define S second
int get_long(pair<int,int> v){
	return abs(v.F-v.S);
}
int main(){
	io_op
	int m,t;
	cin >> m >> t;
	vector<pair<int,int>>v(t);//<end,start>
	for(int i = 0; i<t; i++){
		int s,e;
		cin>> s >> e;
		v[i]={e,s};
	}
	sort(v.begin(),v.end());
	int cnt = get_long(v[0]);
	int ans = 0;
	
	for(int i = 1; i<t; i++){
		if(v[i].S==v[i-1].F){
			cnt+=get_long(v[i]);
			cout << cnt << " ";
		}else{
			ans = max(ans,cnt);
			cnt=get_long(v[i]);
		}
	}
	cout << ans << endl;
}
