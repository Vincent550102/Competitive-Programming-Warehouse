#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	
	while(cin >> N){
		map<int,int> dic;
		vector<int> vec;
		vec.resize(N+1);
		for(int i = 0; i<N; i++){
			cin >> vec[i];
			dic[vec[i]] ++;
		}
		
		int maxval = -1;
		int maxpos = -1;
		sort(vec.begin(),vec.end());
		for(auto x:vec){
			if(maxval<dic[x]){
				maxval = dic[x];
				maxpos = x;
			}
		}
		cout << maxpos << endl;
	}
	
}
