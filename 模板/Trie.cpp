#include<bits/stdc++.h>
using namespace std;
constexpr int mxN = 1e5;
constexpr int mxW = 26;

int Trie[mxN][mxW], last[mxN], pos=0;
//build trie
void Insert(string &s){
	int now = 0;
	for(char c:s){
		if(Trie[now][c-'a']==0){
			Trie[now][c-'a']=++pos;
		}
		now = Trie[now][c-'a'];
	}
	last[now]++;
}

void Print(int now, string &s){
	for(int i = 0; i<last[now]; i++){
		cout << s << endl;
	}
	for(int i = 0; i<mxW; i++){
		if(Trie[now][i]){
			s+='a'+i;
			Print(Trie[now][i],s);
			s.pop_back();
		}
	}
}

int main(){
	int n;cin >> n;
	for(int i = 0; i<n; i++){
		string s;cin >> s;
		Inserts(s);
	}
	string str;cin >> str;
	Print(0,str);
}
