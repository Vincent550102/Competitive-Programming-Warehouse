#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
#define ALL(x) x.begin(),x.end()
using ll = long long;
#define int ll
signed main(){
	FAST
	int t;cin >> t;while(t--){
		int n,k;
		cin >> n >> k;
		string str;cin >> str;
		int lamp_num = 0;
		for(int i = 0; i<n; i++){
			if(str[i]=='1')lamp_num++;
		}
		bool flag = false;
		for(int i = 0; i<n-k; i++){
			if(str[i]=='1' || str[i+k]=='1')flag = true;
		}
		if(flag){
			if(lamp_num<2)cout << "0";
			else cout << lamp_num-2;
		}else{
			if(!lamp_num)cout << "2";
			else cout << lamp_num;
		}
		cout << endl;
	}
}
