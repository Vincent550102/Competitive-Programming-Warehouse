#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

constexpr int mxN = 10;
vector<int> v;
bool flag = 1;
bool vaild(int x){
	if(x<v.size())return 1;
	return 0;
}

void dfs(int x,int r){
//	cout << x << " ";
	if(x==v.size()-1) flag = 0;
	for(int i = 1; i<=r; i++){
		if(vaild(x+i))dfs(x+i,v[x+i]);
	}
}

int main(){
	string str;	
	getline(cin,str);
	stringstream ss;
	ss<<str;
	int tmp;
	while(ss >> tmp){
		v.emplace_back(tmp);
	}
//	cout << v.size();
	dfs(0,v[0]);
	if(flag)cout << "False";
	else cout << "True";
	cout << endl;
	
}
