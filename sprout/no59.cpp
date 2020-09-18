#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0); 
using namespace std;
int main(){
	FAST
	priority_queue<int,vector<int>,greater<int> >M;
	int t;cin >> t;while(t--){
		int q;cin >> q;
		if(!(q-1)){
			int tmp;cin >> tmp;
			M.push(tmp);
		}else{
			if(M.empty())cout << "empty!";
			else{
				cout << M.top() << endl;
				M.pop();
			}
		}
	}
} 
