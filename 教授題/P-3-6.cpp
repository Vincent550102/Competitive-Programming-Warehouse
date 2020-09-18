#include<bits/stdc++.h>

//6 140
//10 30 50 70 100 125
//30 15 55 10 55 25

using namespace std;
const int inf = 1e9+5;
int main(){
	int n,L;
	cin >> n >> L;
	vector<int> v(n+2),h(n+2);
	for(int i =1 ; i<=n; i++){
		cin >> v[i];
	}
	for(int i =1 ; i<=n; i++){
		cin >> h[i];
	}
	h[0]=h[n+1]=inf;
	v[0]=0;
	v[n+1]=L;
	stack<int> st; //remain tree
	st.push(0);
	int ans=0,cnt=0;
	for(int i =1 ; i<=n; i++){
		if(v[i]+h[i]<=v[i+1]||v[i]-h[i]>=v[st.top()]){//can remove
			ans = max(ans,h[i]);
//			cout << v[i] << " ";
			while(v[st.top()]+h[st.top()]<=v[i+1]){
				cnt++;
				ans = max(ans,h[st.top()]);
//				cout << v[st.top()] << " ";
				st.pop();
			}
			cnt++;
		}else{
			st.push(i);
		}
	}
	
	#define _ << endl <<
	cout << cnt _ ans << endl;
}
