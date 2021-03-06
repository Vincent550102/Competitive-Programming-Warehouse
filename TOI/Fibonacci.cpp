#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1000000007;

struct mat{
	ll data[2][2] = {{1,0},{0,1}};
	void init(){
		for(int i = 0; i<2; i++){
			for(int j = 0; j<2; j++){
				data[i][j]=0;
			}
		}
	}
};

mat mul(mat a, mat b){
	mat rul;
	rul.init();
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			for(int k = 0; k<2; k++){
				rul.data[i][j]=(rul.data[i][j]+a.data[i][k]*b.data[k][j]%MOD)%MOD;
			}
		}
	}
	return rul;
}

mat matpow(mat n, int p){
	mat rul;
	while(p){
		if(p&1) rul = mul(rul, n);
		n = mul(n,n);
		p>>=1;
	}
	return rul;
}

int main(){
	ll x1,x2,n;
	mat MAT;
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			MAT.data[i][j]=(!i&&!j?0:1);
		}
	}
	cin >> x1 >> x2 >> MAT.data[0][1] >> MAT.data[1][1] >> n;
	MAT = matpow(MAT,n-2);
//	for(int i = 0; i<2; i++){
//		for(int j = 0; j<2; j++){
//			cout << MAT.data[i][j] << " ";
//		}
//		cout << endl;
//	}
	ll ans = (x1*MAT.data[0][1]%MOD+x2*MAT.data[1][1]%MOD)%MOD;
	cout << ans << endl;
	
	
}
