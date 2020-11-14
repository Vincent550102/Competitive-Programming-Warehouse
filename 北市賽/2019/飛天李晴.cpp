#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
#define _ <<" "<<
int main(){
	io_op
	int n;
	cin >> n;
	vector<pii> v(n);
	for(int i = 0; i<n; i++){
		int a,b,h;
		cin >> a >> b >> h;
		v[i].F = a*a+b*b;
		v[i].S = h;
	}
	sort(v.begin(),v.end());
	stack<int> st;
	st.push(v[1].S);
	int max_dev = -1;
	int MAX = st.top();
	for(int i = 0; i<n; i++){
		if(!st.empty()&&v[i].S>st.top()){
			st.push(v[i].S);
		}else{
			if(max_dev<st.top()-v[i].S){
				max_dev = st.top()-v[i].S;
				MAX = st.top();
			}
		}
	}
	cout << max_dev;
	cout << endl;
	
}
