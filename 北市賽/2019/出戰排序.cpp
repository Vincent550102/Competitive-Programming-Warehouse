#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int main(){
//	io_op
	//O(n*(n+nlogn))
	int n,k;
	while(cin >> n >> k){
		k--;
		for(int m = 2; m<=10*n; m++){
			vector<int> v(n);
			for(int i = 0; i<n; i++){
				v.push_back(i+1);
			}
			int now = m-1;
			now%=v.size();
			while(v.size()!=1){
				v.erase(v.begin()+now);
				now+=m-1;
				now%=v.size();
			}
			if(*v.begin()==k+1){
				cout << (m>30000?'0':m) << endl;
				break;
			}
		}
	}
}
