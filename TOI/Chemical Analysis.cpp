#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

map<string,int> db;
    


bool is_apha(char c){
	return '0'<=c&&c<='9';
}

bool is_big(char c){
	return 'A'<=c&&c<='Z';
}

bool is_small(char c){
	return 'a'<=c&&c<='z';
}

// is_apha is_big is_small

#define PB push_back

vector<pair<string,int>> trans(string str){
	vector<pair<string,int>> flix_str;
	string cur = "";
	// ( 0
	// ) 1
	// word 2
	// number 3
	for(int i = 0, sz = str.size(); i<sz; i++){
//		cout << str[i] << endl;
		cur = "";
		if(str[i]=='('){
			flix_str.PB({"(",0});
		}
		if(str[i]==')'){
			flix_str.PB({")",1});
		}
		if(is_big(str[i])){
			cur+=str[i];
			if(i+1<sz&&is_small(str[i+1])){	
				cur+=str[i+1];
				i++;
			} 
			flix_str.PB({cur,2});
		}
		if(is_apha(str[i])){
			cur+=str[i];
			while(i+1<sz&&is_apha(str[i+1])){
				i++;
				cur+=str[i];
			}
			flix_str.PB({cur,3});
		}
	}
	flix_str.PB({"null",-1});
	return flix_str;
}


// ( 0
// ) 1
// word 2
// number 3
void solve(vector<pair<string,int>> str, int times = 1){
	if(!str.size())return;
	for(int i = 0, sz = str.size(); i<sz; i++){
		if(str[i].S==2){
			if(i+1<sz && str[i+1].S==3){
				db[str[i].F] += stoi(str[i+1].F)*times;
//				cout << str[i].F << " " << stoi(str[i+1].F) << " " << times<< endl;
				i++;
			}else db[str[i].F] += 1*times;
		}
		if(str[i].S==0){
			int nok = 1;
			vector<pair<string,int> > nstr;
			while(nok){
				i++;
				if(str[i].S==0) nok++;         // (
				else if(str[i].S==1) nok--;   // )
				if(nok) nstr.PB(str[i]);
			}
//			if(str[i+1].S==3) cout << times << " " << (int)stoi(str[i+1].F) << endl;
//			for(auto x:nstr){
//				cout << x.F <<":"<< x.S<<endl;
//			}
			solve(nstr, (str[i+1].S==3?times*stoi(str[i+1].F):times));
		}
	}
	
}

int main(){
	string str;
	cin >> str;
	cout << str << endl;
	auto flex_str = trans(str);
	solve(flex_str);
//	for(auto x: flex_str){
//		cout << x.F <<" " << x.S << endl;
//	}
	for(auto x:db){
		cout << x.F <<":"<< x.S<<endl;
	}
}
