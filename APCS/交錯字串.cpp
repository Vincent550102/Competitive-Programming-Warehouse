#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;cin >> k;
	string str;cin >> str;
	int len = str.size();
	bool is_big;
	if(str[0]>='a') is_big=0;
	else is_big=1;
	int cnt = 1;
	vector<int> chk;
//	cout << len;
//	cout << is_big;
	for(int i = 1; i<len; i++){
		if(is_big){
//			cout << "dd";
			if(str[i]<='Z')cnt++;
			else{
				is_big = 0;
				chk.emplace_back(cnt);
				cnt = 1;
			}
		}else{
			if(str[i]>='a')cnt++;
			else{
				is_big = 1;
				chk.emplace_back(cnt);
				cnt = 1;
			}
		}
	}
	chk.emplace_back(cnt);
	int a_cnt;
	if(chk[0]>=k)a_cnt=1;
	else a_cnt = 0;
	int ans = 0;
	int u_num = chk[0];
	for(int i = 1; i<(int)chk.size();i++){
		if(chk[i]<=u_num&&chk[i]==k)a_cnt++;
		else{
			if(chk[i]>=k)a_cnt++;
			ans = max(ans,a_cnt);
			if(chk[i]>=k)a_cnt = 1;
			else a_cnt = 0;
		}
		u_num = chk[i];
	}
	ans = max(ans,a_cnt);
	cout <<k*ans << endl;
	
}
