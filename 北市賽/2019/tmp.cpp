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
	vector<int> v(n);
	for(int &x:v){
		cin >> x;
	}
	stack<int> st;
	st.push(v[0]);
	int max_dev = -1;
	int MAX = st.top();
	int MIN = -1;
	for(int i = 0; i<n; i++){
		if(!st.empty()&&v[i]>st.top()){
			st.push(v[i]);
		}else{
			if(max_dev<st.top()-v[i]){
				max_dev = st.top()-v[i];
				MAX = st.top();
				MIN = v[i];
			}
		}
	}
	cout << MAX _ MIN << endl;
	
}
