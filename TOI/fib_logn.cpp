#include<bits/stdc++.h>
using namespace std;

struct mat{
	int data[2][2]={{1,0},{0,1}};
	void init(){
		for(int i = 0; i<2; i++){
			for(int j = 0; j<2; j++){
				data[i][j]=0;
			}
		}
	}
};
int MOD = 1e9;
mat mul(mat a, mat b){
	mat sul;
	sul.init();
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			for(int k = 0; k<2; k++){
				sul.data[i][j]=(sul.data[i][j]+a.data[i][k]*b.data[k][j])%MOD;
			}
		}
	}
	return sul;
}

mat matpow(mat n, int p){
	mat rESULt;
	while(p){
		if(p&1) rESULt=mul(n,rESULt);
		n = mul(n,n);
		p>>=1;
	}
	return rESULt;
}

int main(){
	mat trans;
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			trans.data[i][j]=(!i&&!j?0:1);
		}
	}
	
	mat m3 = matpow(trans,10);
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			cout << m3.data[i][j] << " ";
		}
		cout << endl;
	}
}
