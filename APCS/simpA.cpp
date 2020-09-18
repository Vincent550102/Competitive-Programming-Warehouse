#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin >> str;
	int len  = str.size();
	int cnt = 0;
	vector<string> v;
	for(int i = 0; i<len; i++){
		
		if('A'<=str[i]&&str[i]<='Z'){
			if(!(cnt)){
				while('A'<=str[cnt]&&str[cnt]<='Z'){
					cnt++;
				}
			}
//			cout << i << " " <<cnt << endl;
			v.emplace_back(str.substr(i,cnt));
			i+=cnt;
		}
	}
	for(int i = (int)v.size()-1; i>=0; i--){
		cout << v[i];
		if(i!=0) cout << "<-";
	}
	cout << endl;
}
