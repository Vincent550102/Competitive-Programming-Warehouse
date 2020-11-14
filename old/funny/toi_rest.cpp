#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	map<int,int>num_set;
	for(int i = 0;i <N; i++){
		int tmp;
		cin >> tmp;
		num_set[tmp]++;
	}
	vector<int> pre_ans;
	int max_num_appear = -1;
	int counter = 0;
	for(auto x:num_set){
		cout << x.first << " ";
		counter++;
		if(x.second > max_num_appear){
			pre_ans.clear();
			max_num_appear = x.second;
			pre_ans.emplace_back(x.first);
		}else if(x.second == max_num_appear){
			pre_ans.emplace_back(x.first);
		}
	}
	cout << counter << endl;
	if(pre_ans.size() == N){
		cout << "NO";
	}else{
		for(auto x:pre_ans){
			cout << x << " ";
		}
	}
}
