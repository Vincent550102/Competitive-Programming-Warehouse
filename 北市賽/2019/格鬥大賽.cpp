#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using pii = pair<int,int>;
#define F first
#define S second
constexpr int mxN = 1e6+5e5;
int a[mxN];
int d[mxN];
int ans[mxN] = {0};
bool is_win(int i,int j){
	return (a[i]>a[j]&&d[i]>=d[j])||(a[i]>=a[j]&&d[i]>d[j]);
}

int main(){
	io_op
	int n;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> a[i] >> d[i];
	}
	stack<int> st;
	for(int i = 0; i<n; i++){
		while(!st.empty()&&!is_win(st.top(),i)){
			ans[st.top()] = i-st.top()-1;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		ans[st.top()] +=n-st.top()-1;
		st.pop();
	}
	for(int i = n-1; ~i; i--){
		while(!st.empty()&&!is_win(st.top(),i)){
			ans[st.top()] += st.top()-i-1;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		ans[st.top()]+=st.top();
		st.pop();
	}
	int mx = 0;
	for(int i = 0; i <n ;i++){
		mx = max(mx,ans[i]);
	}
	cout << mx << endl;
}
