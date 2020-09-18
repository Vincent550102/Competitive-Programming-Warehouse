#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin >> t;while(t--){
		int n;
		cin >> n;
		map<int,int> MP;
		int cnt = 0;
		int max_team_num = 0;
		int max_stu = 1;
		for(int i = 0; i<n; i++){
			int tmp; cin >> tmp;
			if(!MP.count(tmp)){
				cnt++;
				MP[tmp] = 1;
			}else{
				MP[tmp]++;
				max_stu=max(max_stu,MP[tmp]);
			}
		}
		
		if(max_stu==cnt)cout << cnt-1;
		else cout << min(max_stu,cnt);
		cout << endl;
	}
}
