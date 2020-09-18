#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define int ll
signed main(){
	int t;cin >> t;while(t--){
		int n;
		cin >> n;
		int nex;
		stack<int> st;
		for(int i =0 ;i <n; i++){
			int tmp;
			cin >> tmp;
			if(!st.empty()){
				if(st.top()>0){
					if(tmp>0){
						if(st.top()<tmp){
							st.pop();
							st.push(tmp);
						}
					}else{
						st.push(tmp);
					}
				}else{
					if(tmp>0){
						st.push(tmp);
					}else{
						if(st.top()<tmp){
							st.pop();
							st.push(tmp);
						}
					}
				}
			}else st.push(tmp);
		}
		vector<int> v;
		while(!st.empty()){
			v.emplace_back(st.top());
			st.pop();
		}
		int ans = 0;
		for(int x:v)ans+=x;
		cout << ans << endl;
		
	}
}
