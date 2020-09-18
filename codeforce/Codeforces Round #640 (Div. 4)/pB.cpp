#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >> t;while(t--){
		int a,b;
		cin >> a >> b;
		if(b>a){
			cout << "NO\n";
			continue;
		}
		int cnt = 0;
		if(a-2*(b-1)>0){
			if((a-2*(b-1))%2==0){
				cout << "YES\n";
				cout << (a-2*(b-1)) << " ";
				for(int i = 0; i<b-1; i++)cout << "2 ";
				cout << endl;
				continue;
			}else{
				cnt++;
			}
		}else{
			cnt++;
		}
		if((a-b+1)%2==1){
			cout << "YES\n";
			cout << (a-b+1) << " ";
			for(int i = 0; i<b-1; i++)cout << "1 ";
			cout << endl;
			continue;
		}else{
			cnt++;
		}
		if(cnt==2){
			cout << "NO\n";
			
		}
	}
}
