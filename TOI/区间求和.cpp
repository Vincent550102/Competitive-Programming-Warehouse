#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
	int val,tag;
	Node *lc, *rc;
	Node(){
		val=tag=0;
		lc=rc=NULL;
	}
	void pull(){
		val = lc->val+rc->val;
	}
};

vector<int> v;

Node *build(int L,int R){
	Node *node = new Node();
	if(L==R){
		node->val = v[L];
		return node;
	}
	int mid = L+R>>1;
	node->lc = build(L, mid);
	node->rc = build(mid+1, R);
	node->pull();
	return node;
}

void push(Node *node, int L, int R){
	if(L!=R){
		int mid = L+R>>1;
		node->lc->tag += node->tag;
		node->rc->tag += node->tag;
		node->lc->val += node->tag*(mid-L+1);
		node->rc->val += node->tag*(R-mid);
	}
	node->tag=0;
}

void modify(Node *node, int L, int R, int ql, int qr, int d){
	if(R<ql|| qr<L){
		return;
	}
	if(ql<=L&&R<=qr){
		node->val+=d*(R-L+1);
		node->tag+=d;
		return;
	}
	push(node, L, R);
	int mid = L+R>>1;
	modify(node->lc, L, mid, ql, qr, d);
	modify(node->rc, mid+1, R, ql, qr, d);
	node->pull();
}

int query(Node *node, int L, int R, int ql, int qr){
	if(R<ql || qr<L){
		return 0;
	}
	if(ql<=L&&R<=qr){
		return node->val;
	}
	push(node, L, R);
	int mid = L+R>>1;
	return query(node->lc, L, mid, ql, qr)+query(node->rc, mid+1, R, ql, qr);
}

signed main(){
	int n;cin >> n;
	v.resize(n+1);
	for(int i = 1; i<=n; i++){
		cin >> v[i];
	}
	Node *sgt = build(1,n);
//	cout << sgt->rc->lc->val;
	int q; cin >> q;
	while(q--){
		int qi,x,y;cin >> qi >> x >> y;
		if(qi == 1){
			int k;cin >> k;
			modify(sgt,1,n,x,y,k);
		}else{
			cout << query(sgt,1,n,x,y) << endl;
		}
	}
}
