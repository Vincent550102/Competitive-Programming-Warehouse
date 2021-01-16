#pragma GCC optimize("O3,unroll-loops")
#pragma loop_opt(on)
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
#define endl '\n'

#define coutv(v) for(auto x:v){\
	cout << x << " ";\
}cout << '\n';

constexpr ll mxN = 1e4;
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
vector<int> v1;
vector<int> v2;
struct Node1{
	int val;
	Node1 *lc ,*rc;
	Node1(){
		val = INT_MAX;
		lc=rc=NULL;
	}
	void pull(){
		val = min(lc->val,rc->val);
	}
};

Node1 *build1(int L,int R){
	Node1 *node1 = new Node1();
	if(L==R){
		node1->val = v1[R];
		return node1;
	}
	int mid = (L+R)>>1;
	node1->lc = build1(L,mid);
	node1->rc = build1(mid+1,R);
	node1->pull();
	return node1;
}

int query1(Node1 *node1,int L,int R, int ql,int qr){
	if(ql>R||qr<L)return INT_MAX;
	if(ql<=L && R<=qr)return node1->val;
	int mid = (L+R)>>1;
	return min(query1(node1->lc,L,mid,ql,qr),query1(node1->rc,mid+1,R,ql,qr));
}


struct Node2{
	int val;
	Node2 *lc ,*rc;
	Node2(){
		val = 0;
		lc=rc=NULL;
	}
	void pull(){
		val = max(lc->val,rc->val);
	}
};

Node2 *build2(int L,int R){
	Node2 *node2 = new Node2();
	if(L==R){
		node2->val = v2[R];
		return node2;
	}
	int mid = (L+R)>>1;
	node2->lc = build2(L,mid);
	node2->rc = build2(mid+1,R);
	node2->pull();
	return node2;
}

int query2(Node2 *node2,int L,int R, int ql,int qr){
	if(ql>R||qr<L)return 0;
	if(ql<=L && R<=qr)return node2->val;
	int mid = (L+R)>>1;
	return max(query2(node2->lc,L,mid,ql,qr),query2(node2->rc,mid+1,R,ql,qr));
}

int main(){
	io_op
	int k,ans = 0;
	cin  >> n >> k;
	v1.resize(n+1);
	v2.resize(n+1);
	for(int i = 1; i<=n; i++){
		int tmp;cin >> tmp;
		v1[i]=v2[i]=tmp;
	}
	Node1 *seg_min = build1(1,n);
	Node2 *seg_max = build2(1,n);
	for(int i = 1; i<=n; i++){
		for(int j = i; j<=n; j++){
			int Max = query2(seg_max,1,n,i,j);
			int Min = query1(seg_min,1,n,i,j);
			if(Max-Min<=k)ans++;
			else break;
		}
	}
	cout << ans <<endl;
}
