#include<bits/stdc++.h>
using namespace std;
constexpr int mxN = 1e5;
string er= "er...";
vector<int> build_fail(string a){
	int pos;
	vector<int> f((int)a.size());
	f[0] = pos = -1;
	for(int i = 1; i<a.size(); i++){
		while(pos!=-1&&a[pos+1]!=a[i])pos = f[pos];
		if(a[pos+1]==a[i])pos++;
		f[i]=pos;
	}
	return f;
}


void change(string &tar, int pos){
	string rel = "";
	rel+=tar.substr(0,pos);
	rel+=tar.substr(pos+5,tar.size()-pos-5);
	tar = rel;
}

int main(){
//	for(int i = 0; i<5; i++){
//		cout << f[i] << " ";
//	}
	string a;
	while(getline(cin,a)){
		vector<int> f = build_fail(a);
		int now = -1;
		vector<int> cha;
		for(int i = 0; i<a.size(); i++){
			while(now!=-1&&er[now+1]!=a[i])now = f[now];
			if(er[now+1]==a[i])now++;
			if(now+1 == er.size()){
				cha.push_back(i - er.size()+1);
				
				now = f[now];
			}
		}
		for(int i = cha.size()-1; i>=0; i--){
			change(a, cha[i]);
		}
		string ans = "";
		string cur = "";
		bool start = true;
		bool jump = false;
		for(int i = 0; i<a.size(); i++){
			while(start&&a[i]==' '){
				i++;
			}
			start = false;
			if(i>0&&a[i]==' '&&a[i-1]==' ')continue;
			else if(a[i]=='$')jump = true;
			else if(a[i]=='.'){
				if(!jump){
					ans+=cur+'.';
				}
				start = true;
				jump = false;
				cur = "";
			}else cur+=a[i];
		}
		cout << ans << endl;
	}
	
} 
