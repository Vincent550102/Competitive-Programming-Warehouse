#include<bits/stdc++.h>
#define mk make_pair
using namespace std;
bool ismall(char x){
	if(x>='a' && x<='z'){
		return true;
	}else{
		return false;
	}
}

int main(){
	int N;
	cin >> N;
	string str;
	cin >> str;
	vector<pair<bool,int>>vec;
	int len = str.size();
	int status = ismall(str[0]);
	int tmp = 0;
	for(int i =0; i<len; i++){
		if(status == ismall(str[i])){
			tmp++;
		}else{	
			vec.push_back(mk(status,tmp));
			status = ismall(str[i]);
			tmp = 1;
		}
	}
	if(tmp > 0){
		vec.push_back(mk(status,tmp));
	}
	int temp = 0;
	int ans = 0;
	
	for(int i = 0; i < vec.size(); i++){
		if(temp == 0){ //剛開始 
			if(vec[i].second >= N){
				temp+=N;
			}
		}else{ //非剛開始 
			if(vec[i].second == N){
				temp+=N;
			}else{
				if(vec[i].second > N){
					temp += N;
				}
				ans = max(temp,ans);
				if(vec[i].second > N){
					temp = N;
				}else{
					temp = 0;
				}
			}
		}
	}	
	
	if(temp > 0){
		ans = max(temp,ans);
	}
	cout << ans << '\n';
}
