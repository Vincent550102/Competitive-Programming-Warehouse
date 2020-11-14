#include<bits/stdc++.h>

using namespace std;
pair<int,string> apple(){
	return make_pair(1,"dwd");
}
int main(){
	vector<pair<string,string>> food;
	vector<string>Lovefood;
	int N;
	cin >> N;
	string tmpA,tmpB,check;
	for(int i = 0; i<N; i++){
		cin >> tmpA;
		cin >> tmpB;
		food.push_back(make_pair(tmpA,tmpB));
	}
	
	cin >> check;
	for(int i = 0; i<N; i++){
		if(food[i].second == check){
			Lovefood.push_back(food[i].first);
		}
	}
	sort(Lovefood.begin(),Lovefood.end());
	if(Lovefood.empty()){
		cout << "No";
	}else{
		for(int i = 0; i<Lovefood.size();i++){
			cout << Lovefood[i]<<"\n";
		}
	}
	
}
