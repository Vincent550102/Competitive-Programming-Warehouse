#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >> t;while(t--){
		int n,x,y,z;
		cin >> n >> x >> y >> z;
		vector<int> ele(n);
		vector<int> requr(n);
		for(int i = 0; i<n; i++)cin >> ele[i];
		for(int i = 0; i<n; i++)cin >> requr[i];
		for(int i = 0; i<z; i++){
			ele.erase(max_element(ele.begin(),ele.end()));
			requr.erase(max_element(requr.begin(),requr.end()));
		}
		n-=z;
		deque<int> dq;
		bool flag = true;
//		cout << "n : "<< n << endl;
		int idx = 0;
//		for(int x:ele)cout << x <<" ";
//		cout << endl;
//		for(int x:requr)cout << x << " ";
//		cout << endl;
		for(int i = 0; i<n; i++){
			dq.push_back(ele[i]);
			while(!dq.empty()&&((dq.front() == requr[idx])&&x!=0) || ((dq.back() == requr[idx])&&y!=0)){
				if((dq.front() == requr[idx])&&x!=0){
					dq.pop_front();
					x--;
					idx++;
				}
				if((dq.back() == requr[idx])&&y!=0){
					cout<<idx<<" : "<<dq.back()<< " " <<requr[idx] << endl;
					dq.pop_back();
					y--;
					idx++;
					
				}
				cout << x << " " << y << endl;
				
			}
//			for(int x:dq)cout <<x <<" ";
//			cout << endl;
		}
		if(dq.empty())cout << "yes";
		else cout << "no";
		cout << endl;
		
	}
	
}
