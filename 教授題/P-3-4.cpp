#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
signed main(){
	int n;
	cin >> n;
	vector<int> v(n);
	stack<int> st;
	for(int i = 0; i<n; i++){
		cin >> v[i];
	}
	int ans = 1;
	st.push(0);
	for(int i = 1; i<n; i++){
		while(!st.empty()&&v[st.top()]<=v[i]){
			st.pop();
		}
		ans+=st.empty()?i+1:i-st.top();
		st.push(i);
	}
	cout << ans << endl;
} 
