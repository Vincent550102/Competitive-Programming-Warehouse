#include<bits/stdc++.h>
#include<unordered_map> 

using namespace std;
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
#define int ll
using pii = pair<int,int>;
#define F first
#define S second
constexpr int mxN = 1e2+5;
int m;
vector<int> buf[mxN];

int pow_mod(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res=(res * n)%m;
		n = (n*n)%m;
		p>>=1;
	}
	return res;
}
int n;
signed main(){
	io_op
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		buf[i].resize(n+1);
		cin >> buf[i][n];
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cin >> buf[j][i];
		}
	}
		
	for(int i = 0; i<n; i++){
		int change_cnt = i+1;
		bool ok = 0;
		while(!buf[i][i]){
			if(change_cnt>=n){
				ok = 1;
				break;
			}
			swap(buf[change_cnt],buf[i]);
			change_cnt++;
		}
		if(ok)break;
		int mie = pow_mod(buf[i][i],m-2);
		for(int j = i; j<n+1; j++){
			buf[i][j] = (buf[i][j]*mie)%m;
		}
		for(int j = i+1; j<n; j++){
			for(int k = i+1; k<n+1; k++){
				buf[j][k] = ((buf[j][k]%m - buf[j][i]%m*buf[i][k]%m)%m+m)%m;
			}
			buf[j][i]=0;
		}
	}
//	for(int i = 0; i<n; i++){
//		for(int x:buf[i])cout << x <<" ";
//		cout <<endl;
//	}
	for(int i = n-1; i>=1; i--){
		for(int j = i; j<n; j++){
			buf[i-1][n] = ((buf[i-1][n]%m-buf[j][n]%m*buf[i-1][j]%m)%m+m)%m;
			buf[i-1][j] = 0;
		}
	}
	for(int i = 0; i<n; i++){
		cout << (buf[i][n]+m)%m << " ";
	}
	cout << endl;
	
}
