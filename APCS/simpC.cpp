#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	map<int,int> MP;
	for(int i = 0; i<n; i++){
		int tmp;
		cin >> tmp;
		if(!MP.count(tmp)){
			MP[tmp] = 1;
		}else{
			MP[tmp]++;
		}
	}
	int ans = 0;
	vector<int>v;
	for(auto x:MP){
		v.emplace_back(x.second);
	}
	sort(v.begin(),v.end());
	bool ok = false;
	int len = v.size();
	for(int i = 0; i<len; i++){
		v[i] -= v[i]/3*3;
		if(v[i]==2){
			ok = true;
			v.erase(v.begin()+i);	
		}
	}
	if(ok){
		for(int x:v)if(x==1)ans++;
	}else{
		for(int i = 0; i<len; i++){
			if(v[i]==1){
				for(int j = i+1; j<len;j++){
					if(v[j]==1){
						v.erase(v.begin()+i);
						v.erase(v.begin()+j);
						ok = true;
						break;
					}
				}
			}
			if(ok)break;
		}
		for(int x:v)if(x==1)ans++;
	}
	
	cout << ans << endl;
}
