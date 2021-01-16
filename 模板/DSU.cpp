#include<bits/stdc++.h>
using namespace std;
constexpr int mxN = 1e5;
struct DSU{
	int f[mxN];
	void init(int n){
		for(int i = 0; i<n; i++){
			f[i]=i;
		}
	}
	int query(int n){
		return (f[n]==n)?n:f[n]=query(f[n]);
	}
	void unite(int a,int b){
		f[query(a)]=query(b);
	}
};

int main(){
	
}
