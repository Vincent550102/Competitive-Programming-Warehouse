#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<ll,ll>
#define F first
#define S second
#define int ll
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
ll operator^(const pii &p1, const pii &p2){
	return p1.F*p2.S - p1.S*p2.F;
}
ll operator*(const pii &p1, const pii &p2){
	return p1.F*p2.F + p1.S*p2.S;
}
pii operator+(const pii &p1, const pii &p2){
	return {p1.F+p2.F,p1.S+p2.S};
}
pii operator-(const pii &p1, const pii &p2){
	return {p1.F-p2.F,p1.S-p2.S};
}
bool in_segment(pii p1, pii p2, pii q){
	return ((p1-q)^(p2-q))==0 && ((p1-q)*(p2-q))<=0;
}
int ori(ll x){
	return (x>0)-(x<0);
}
bool banana(pii p1, pii p2, pii q1,pii q2){
	if(in_segment(p1,p2,q1)||in_segment(p1,p2,q2)||in_segment(q1,q2,p1)||in_segment(q1,q2,p2)){
		return true;
	}else if(ori((p2-q1)^(p1-q1)) *ori((p2-q2)^(p1-q2))==-1&&ori((q2-p1)^(q1-p1))*ori((q2-p2)^(q1-p2))==-1){
		return true;
	}else{
		return false;
	}
}
signed main(){
	IO_OP
	int t;cin >> t;while(t--){
		int x1,y1,x2,y2,x3,y3,x4,y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		bool flag = banana({x1,y1}, {x2,y2}, {x3,y3},{x4,y4});
		if(flag)cout << "Yes";
		else cout << "No";
		cout << endl;
	}
}
