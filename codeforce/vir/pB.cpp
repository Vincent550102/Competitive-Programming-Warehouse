#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
using pii = pair<int,int>;
#define F first
#define S second
constexpr int mxN = 1e3+5;
bool table[mxN]={0};

void build(){
	for(int i = 2; i<mxN; i++){
		if(!table[i]){
			for(int j = i+i; j<mxN; j+=i){
				table[j]=1;
			}
		}
	}
}

void solve(){
	int a,b;cin >> a >> b;
	string str;cin >> str;
	vector<pii> v;
	str+="00";
	bool ok = 0;
	int l;
	for(int i = 0,sz=str.size(); i<sz; i++){
		if(!ok and str[i]=='1'){
			ok=1;
			l=i;
		}
		if(ok and str[i+1]=='0'){
			ok=0;
			v.push_back({l,i});
		}
	}
//	for(auto x:v){
//		cout << x.F << " " << x.S << endl;
//	}
	int cost = 0;
	bool act = 0;
	for(int i = 0,sz=v.size();i<sz-1; i++){
		if((v[i+1].F-v[i].S-1)*b<a){
			cost+=(v[i+1].F-v[i].S-1)*b;
		}else{
			cost+=a;
		}
	}
	if(!v.empty())cost+=a;
	cout << cost << endl;
}
int main(){
	//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
	//2*2
	io_op
	table[1]=1;
//	build();
	int t;cin >>t;while(t--){
		solve();
	}
	
}
