#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int mxN = 1e6;
int cutpos[mxN];
int ans = 0;
#define _ <<" "<<
int n,l;
void recur(int l,int r){
	int m = l+r>>1;
	int lb=0,rb=n-1,mb;
	while(rb>=lb){
		mb = lb+rb>>1;
		if(cutpos[mb]>m)rb=mb-1;
		else if(cutpos[mb]<m)lb=mb+1;
		else break;
	}
//	if(cutpos[mb]>m)mb--;
	if(l<cutpos[mb]&&cutpos[mb]<r){
//		cout << mb << ":"<<cutpos[mb] << endl;
		ans+=cutpos[mb]-l+r-cutpos[mb];
		recur(l,cutpos[mb]);
		recur(cutpos[mb],r);
	}else{
		return;
	}
}

signed main(){
	cin >> n >> l;
	for(int i = 0; i<n; i++){
		cin >> cutpos[i];
	}
	recur(0,l);
	cout << ans << endl;
}
