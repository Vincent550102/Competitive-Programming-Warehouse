#include<bits/stdc++.h>
using namespace std;
int main(){
	int w,h,n;
	cin >> w >> h >> n;
	vector<pair<char,pair<int,int> > > v;
	for(int i = 0; i<w; i++){
		for(int j = 0; j<h; j++){
			char tmp;
			cin >> tmp;
			if(tmp!='0')v.emplace_back(make_pair(tmp,make_pair(i,j)));
		}
	}
	sort(v.begin(),v.end());
	if(v.size()<n)cout << "Mission fail.\n";
	else{
		for(int i = 0; i<n; i++){
			cout << v[i].second.first << " " << v[i].second.second << endl; 
		}
	}
}
