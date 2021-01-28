#include<bits/stdc++.h>
using namespace std;


using ll = long long;
using pii = pair<int,int>
#define F first
#define S second
#define endl '\n'

constexpr int mxN = 1e5+5;

int n;
vector<int> v;
struct Node{
	int val,tag;
	int cnt;
	Node *lc ,*rc;
	Node(){
		cnt = val = tag = 0;
		lc = rc = NULL;
	}
	void pull(){
		val = lc->val + rc->val;
	}
};

Node *build(int L,int R){
	Node *node = new Node();
	if(L==R){
		node->val = v[R];
		return node;
	}
	int mid = (L+R)>>1;
	node->lc = build(L,mid);
	node->rc = build(mid+1,R);
	node->pull();
	return node;
}

void push(Node *node,int L,int R){
	if(!node->tag)return;
	if(L!=R){ //check not leaf
		int mid = (L+R)>>1;
		node->lc->tag += node->tag;
		node->rc->tag += node->tag;
		node->lc->val += node->tag*(mid-L+1);
		node->rc->val += node->tag*(R-mid);
	}
	node->tag = 0;
}

void modify(Node *node ,int L, int R, int ql, int qr, int d){
	if(ql>R||qr<L)return;
	if(ql<=L&&R<=qr){
		node->tag+=d;
		node->val+=d*(R-L+1);
		return;
	}
	push(node,L,R);
	int mid = (L+R) >> 1;
	modify(node->lc,L,mid,ql,qr,d);
	modify(node->rc,mid+1,R,ql,qr,d);
	node->pull();
}

int query(Node *node,int L,int R, int ql,int qr){
	if(ql>R||qr<L)return 0;
	if(ql<=L && R<=qr)return node->val;
	push(node,L,R);
	int mid = (L+R)>>1;
	return query(node->lc,L,mid,ql,qr)+query(node->rc,mid+1,R,ql,qr);
}

int main(){
	// n
	// l r u d
	cin >> n;
	//vector<l,{{u,d},cnt}>
	
	Node *seg = build(1,n);
	
	vector<pair<int,pair<pair<int,int>,int > > > G;
	for(int i = 0; i<n; i++){
		int l,r,u,d;
		cin >> l >> r >> u >> d;
		G.emplace_back({l,{{u,d},1}});
		G.emplace_back({r,{{u,d},-1}});
	}
	int prev = 0;
	int ans = 0; //query change to check number of not zero
	for(auto E:G){
		ans += query(seg,1,n,1,n)*(pre-E.F);
		modify(seg , 1 , n , E.S.F.F , E.S.F.S , e.S.S);
	}
	cout << ans <<endl;
	
} 
