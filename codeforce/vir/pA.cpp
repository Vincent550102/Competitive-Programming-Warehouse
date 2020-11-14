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
	int n;
	cin >> n;
	int cnt=0;
	for(int i = 2*n; cnt!=n; i+=2,cnt++){
		cout << i << " ";
	}
	cout <<endl;

}
int main(){
	//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
	//2*2
	io_op
	table[1]=1;
	build();
	int t;cin >>t;while(t--){
		solve();
	}
	
}
