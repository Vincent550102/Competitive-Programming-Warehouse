#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool cmp(pair<ll , ll> a, pair<ll , ll> b){
	if(a.second < b.second) return a<b;
}

ll se[100005];

int main(){
	ll N;
	vector<pair<ll , ll> > num_se;
	cin >> N;
	for(int i = 0; i< N; i++){
		cin >> se[i];
		bool flag = true;
		for(auto x:num_se){
			if(se[i] == x.first){
				x.second++;
				flag = false;
			}
		}
		if(flag){
			num_se.emplace_back(make_pair(se[i],0));
		}
	}
	sort(num_se.begin() , num_se.end(), cmp);
	
	ll maxs = num_se[0].second;
	ll g = 0;
	cout << num_se[g].first << num_se[g].second;
	while(num_se[g].second == maxs){
		//cout << num_se[g].first << " " << num_se[g].second << " ";
		g++;
	}
	
}
