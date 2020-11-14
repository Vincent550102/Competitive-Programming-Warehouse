#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

//bool is_prime(int x){
//	for(int i = 2; i<=sqrt(x); i++){
//		if(x%i==0)return 0;
//	}
//	return 1;
//}

int main(){
	string str1,str2;
	while(cin >> str1 >> str2){
		long long num1=0,num2=0;
		int cnt = 0;
		vector<int> v1,v2;
		while(str1[cnt+1]!=']'){
			cnt++;
			if(str1[cnt]==',')continue;
			v1.push_back(str1[cnt]-'0');
		}
		cnt = 0;
		while(str2[cnt+1]!=']'){
			cnt++;
			if(str2[cnt]==',')continue;
			v2.push_back(str2[cnt]-'0');
		}
	//	for(int i = 0,sz = v1.size(); i<sz; i++){
	//		cout << v1[i] << " " << v2[i] << endl;
	//	}
//		reverse(v1.begin(),v1.end());
//		reverse(v2.begin(),v2.end());
		vector<int> ans;
		cnt = 0;
		int ok = 0;
		while(cnt<v1.size()||cnt<v2.size()){
			if(ok){
				ok = 0;
				ans.emplace_back((v1[cnt]+v2[cnt]+1)%10);
				if((v1[cnt]+v2[cnt]+1)>9)ok =1;
			}else{
				ans.emplace_back((v1[cnt]+v2[cnt])%10);
				if((v1[cnt]+v2[cnt])>9)ok =1;
			}
			cnt++;
		}
		if(ok)ans.emplace_back(1);
//		for(int i = v1.size()-1;~i;i--){
////			cout << v1[i];
//			num1*=10;
//			num1+= v1[i];
//		}
//		for(int i = v1.size()-1;~i;i--){
//			num2*=10;
//			num2+=v2[i];
//		}
//		cout << num1 << " " << num2 << endl;
//		long long ans_num = num1+num2;
//		string s = to_string(ans_num);
//		
		cout << "[";
		for(int i = 0; i<ans.size(); i++){
			cout << ans[i];
			if(i!=ans.size()-1)cout << ", ";
		}
		cout << "]";
		cout << endl;
	}
}
