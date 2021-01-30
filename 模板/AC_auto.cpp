#include<bits/stdc++.h>
using namespace std;
constexpr int mxN = 1e5;
constexpr int mxW = 26;

int Trie[mxN][mxW],fail[mxN],last[mxN],pos=0;

void Insert(string &s){
	int now = 0;
	for(char c:s){
		int &to = Trie[now][c-'a'];
		now = to?to:to=++pos;
	}
	last[now]++;
}
void getAC(){
	queue<int> qu{};
	for(int i = 0; i<mxW; i++){
		if(Trie[0][i])qu.push(Trie[0][i]);
	}
	while(qu.size()){
		int now = qu.front(); qu.pop();
		for(int i = 0; i<mxW; i++){
			int &to = Trie[now][i],tmp;
			if(to==0) to=Trie[fail[now]][i];
			else{
				qu.push(to),tmp = fail[now];
				while(tmp && Trie[tmp][i]==0)tmp = fail[tmp];
				fail[to] = Trie[tmp][i];
				last[to] += last[Trie[tmp][i]];
			}
		}
	}
}

void Matching(string &s){
	int now = 0;
	for(int i = 0; i<s.size(); i++){
		while(now&&Trie[now][s[i]-'a']==0){
			now = fail[now];
		}
		if (Trie[now][s[i]-'a']){
			now = Trie[now][s[i]-'a'];
		}
		if(last[now]>0){
			cout << "Found " << last[now] << " match at " << i << endl;
		}
	}
}

int main(){
	int n;cin >> n;
	for(int i = 0; i<n; i++){
		string in;cin >> in;
		Insert(in);
	}
	getAC();
	string s;
	cin >>s;
	Matching(s);
}
