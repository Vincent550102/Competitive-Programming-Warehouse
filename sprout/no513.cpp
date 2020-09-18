#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
#define int ll
signed main(){
	FAST
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> ans(n,0);
	for(int i = 0; i<n; i++)cin >> v[i];
	stack<int> st1;//excex increase
	for(int i = 0; i<n; i++){
		if(!st1.empty()){
			if(v[st1.top()]<v[i]){
				ans[i]+=1;
				st1.push(i);
			}else{
				while(!st1.empty() && v[st1.top()]>=v[i]){
					st1.pop();
				}
				ans[i] += (st1.empty())?i+1: i-st1.top();
				st1.push(i);
				
			}
		}else{
			st1.push(i);
			ans[i] += 1;
		}
	}
	stack<int> st2;//excex increase
//	for(int i = 0; i<n; i++)cout << ans[i];
//	cout << endl;
	for(int i = n-1; i>=0; i--){
		if(!st2.empty()){
			if(v[st2.top()]<v[i]){
				ans[i]+=0;
				st2.push(i);
			}else{
				while(!st2.empty() && v[st2.top()]>=v[i]){
					st2.pop();
				}
				ans[i] += (st2.empty())?n-i-1: st2.top()-i-1;
				st2.push(i);
			}
		}else{
			st2.push(i);
			ans[i] += 0;
		}
	}
	int max_num = 0;
//	cout << endl;
	for(int i = 0; i<n; i++){
		max_num = max(max_num,v[i]*ans[i]);
//		cout << ans[i] <<" ";
	}
	
	cout << max_num << endl;
} 
