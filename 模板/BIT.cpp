#include<bits/stdc++.h>
using namespace std;
#define Lb(x) x&-x
int n;
struct BIT{
	vector<int> v;
	void modify(int x,int d){
		while(x<=n){
			v[x]+=d;
			x += Lb(x);		
		}
	}
	int query(int x){
		int ans = 0;
		while(x){
			ans+=v[x];
			x-=Lb(x);
		}
		return ans;
	}
};

int main(){
//	int n;
	cin >> n;
	BIT bit;
	bit.v.resize(n+1,0);
	for(int i = 1; i<=n; i++){
		int tmp;
		cin >> tmp;
		bit.modify(i,tmp);
	}
	cout << bit.query(3);
	
}
