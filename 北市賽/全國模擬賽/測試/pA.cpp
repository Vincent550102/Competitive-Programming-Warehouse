#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using pii = pair<int,int>;
using piii = pair<int,pii>;
using ll = long long;
//#define int ll
#define F first
#define S second
#define All(x) x.begin(),x.end()
#define Vi vector<int>
#define Vl vector<ll>
#define Pb push_back
#define Eb emplace_back

#define coutv(v) for(auto x:v){\
	cout << x << " ";\
}cout << '\n';

constexpr ll mxN = 1e7;
constexpr ll MOD = 1e9+7;

/*
ll pow_mod(int n, int p){
	int rESULt = 1;
	while(p){
		if(p&1) rESULt=(rESULt * n)%MOD;
		n = (n*n)%MOD;
		p>>=1;
	}
	return rESULt;
}
*/

int n;

map<string,vector<string> > G;
map<string,string> p;
map<string,int> dep;

void dfs(string v,int d=0){
	for(string x:G[v]){
		dfs(x,d+1);
	}
	dep[v]=d;
}

string Lca(string x, string y) {
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[y] > dep[x]) y = p[y];
	while(x != y) x = p[x], y = p[y];
	return x;
}

int main(){
	io_op
	cin >> n;
	string str;
	stringstream ss;
	cin.ignore();
	for(int i = 0; i<n; i++){
		getline(cin,str);
		ss.clear();ss<<str;
		ss>>str;
		string parent = str;
		while(ss>>str){
			G[parent].emplace_back(str);
			p[str] = parent;
		}
	}
	getline(cin,str);
	ss.clear();ss<<str;
	ss>>str;
	string a = str;
	ss>>str;
	string b = str;
	string root;
	for(auto x:G)if(!p.count(x.F)){ 
		root=x.F; 
		break; 
	} 
	dfs(root);
	string lca = Lca(a,b);
	cout << dep[a]+dep[b]-2*dep[lca] << endl;
}
