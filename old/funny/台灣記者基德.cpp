#include<bits/stdc++.h>

#define f first
#define s second

using namespace std;


int main(){
	int n,k;
	cin >> n >> k;
	pair<int,string> pii[1005];
	for(int i = 0; i<n; i++){
		cin >> pii[i].s >> pii[i].f;
	}
	
	sort(pii,pii+n);
	
	int count = k-1;
	vector<string> anslist;
	for(int i = n-1; i>=0; i--){
		if(count == 0){
			anslist.emplace_back(pii[i].s);
		}
		if(pii[i-1].f == pii[i].f){
			count++;
		}
		count--;
	}
	int len = anslist.size();
	for(int i = len-1; i>=0; i--){
		cout << anslist[i] << '\n';		
	}
}
