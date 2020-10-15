#include<bits/stdc++.h>
#define int ll
#define pii pair<int,int>
#define piii pair<pii,int>
#define F first
#define S second
#define FF F.F
#define FS F.S
using namespace std;
int main(){
	int n;cin >> n;
	vector<piii> v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i].S >> v[i].FF >> v[i].FS;
	}
	
	sort(v.begin(),v.end());
	deque<int> live;
	live.push_back(v[0]);
	for(int i = 1; i<n; i++){
		while(!live.empty())
	}
}
