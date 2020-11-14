#include<bits/stdc++.h>
#define ll long long
#define ss istringstream
using namespace std;
struct food_advis{
	vector<string> tags;
	int price = 0;
	int point = 0;
	int point_s = 0;
}adv[105];

int main(){
	int n;
	cin >> n;
	cin.ignore();
	for(int i = 1; i<=n; i++){
		string tmp;
		getline(cin,tmp);
		int len = tmp.size();
		for(int i = 0; i<len; i++){
			if(tmp[i] == ',') tmp[i] = ' ';
		}
		
		ss pp(tmp);
		int one_num = 0;
		while(pp >> tmp){
			if(tmp[0] >= '0' && tmp[0] <= '9' ){
				if(!one_num){
					one_num = 1;
				}else{
					adv[i].price = stoi(tmp);
				}
			}else{
				adv[i].tags.emplace_back(tmp);
			}
		}
	}
	vector<string> tag;
	string tmps;
	getline(cin,tmps);
	ss pp(tmps);
	while(pp >> tmps){
		tag.emplace_back(tmps);
	}
	int max_relat = -1;
	int max_hi_relat = -1;
	vector<int> probably_ans_relate;
	for( int i = 1; i<=n; i++ ){
		int counter = 0;
		for(auto x:tag){
			for(auto y:adv[i].tags){
				if(x == y) counter++;
			}
		}
// 		3
//		1,a b c,5
//		2,cnj mef ie,1
//		3,a b ef,4
//		a b c
//		for(auto x:adv[i].tags){
//			cout << x <<" ";
//		}
//		cout << endl;
//		cout << endl;
		//cout << counter << " " << adv[i].tags.size() << " " << tag.size() << endl;
		if(counter == 0) adv[i].point = 0;
		else if(counter == adv[i].tags.size() &&counter == tag.size()) adv[i].point = 9;
		else{
			adv[i].point = 6;
			adv[i].point_s = counter;
		} 
		if(max_relat < adv[i].point){
			probably_ans_relate.clear();
			max_relat= adv[i].point;
			probably_ans_relate.emplace_back(i);
		}else if (max_relat == adv[i].point){
			if(max_relat == 6){
				if(max_hi_relat < adv[i].point){
					probably_ans_relate.clear();
					max_hi_relat= adv[i].point;
					probably_ans_relate.emplace_back(i);
				}else if(max_hi_relat < adv[i].point){
					probably_ans_relate.emplace_back(i);
				}
			}else{
				probably_ans_relate.emplace_back(i);
			}
			
		}
	}
	
	int len = probably_ans_relate.size();
	
	int min_price = 99999999;
	int solve_point;
	
	for(int i = len-1 ; i>=0; i--){
		if(min_price > adv[ probably_ans_relate[i] ].price){
			solve_point = probably_ans_relate[i];
			min_price = adv[ probably_ans_relate[i] ].price;	
		}
	}
	cout <<	 solve_point << " " << adv[ solve_point ].point;
}
