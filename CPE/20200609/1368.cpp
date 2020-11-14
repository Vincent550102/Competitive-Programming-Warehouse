#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >> t;
	while(t--){
		int m,n;
		cin >> m >> n;
		vector<string> v(m);
		for(int i = 0; i<m; i++){
			string str;cin >> str;
			v[i] = str;
		}
		//ATCG
		//0123
		int ans = 0;
		for(int i = 0; i<n; i++){
			int cnt[4]={0};
			for(int j = 0; j<m; j++){
				if(v[j][i]=='A')cnt[0]++;//1
				if(v[j][i]=='T')cnt[1]++;//4
				if(v[j][i]=='C')cnt[2]++;//2
				if(v[j][i]=='G')cnt[3]++;//3
			}
			if(cnt[0]>=cnt[1]&&cnt[0]>=cnt[2]&&cnt[0]>=cnt[3]){
				cout << "A";
				ans+=m-cnt[0];
			}
			if(cnt[1]>cnt[0]&&cnt[1]>cnt[2]&&cnt[1]>cnt[3]){
				cout << "T";
				ans+=m-cnt[1];
			}
			if(cnt[2]>=cnt[1]&&cnt[2]>cnt[0]&&cnt[2]>=cnt[3]){
				cout << "C";
				ans+=m-cnt[2];
			}
			if(cnt[3]>=cnt[1]&&cnt[3]>cnt[2]&&cnt[3]>cnt[0]){
				cout << "G";
				ans+=m-cnt[3];
			}
		}
		cout <<endl<< ans << endl;
	}
}
