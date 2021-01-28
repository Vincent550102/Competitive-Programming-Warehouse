#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);

int N, Q;
vector<int> v;
constexpr int INF = INT_MAX;
struct Node{
	int val, mxval, mnval;
	int chatag, addtag;
	Node *lc, *rc;
	Node(){	
		val = mxval = addtag = chatag = 0;
		mnval = INF;
		lc = rc = NULL;
	}
	void pull(){
		val = lc->val + rc->val;
		mxval = max(lc->mxval, rc->mxval);
		mnval = min(lc->mnval, rc->mnval);
	}
};

Node *build(int L, int R){
	Node *node = new Node();
	if(L==R){
		node->val = v[R];
		node->mxval = v[R];
		node->mnval = v[R];
		return node;
	}
	int mid = (L+R)>>1;
	node->lc = build(L, mid);
	node->rc = build(mid+1, R);
	node->pull();
	return node;
}

void push(Node *node, int L, int R){
	if(!node->addtag && !node->chatag)return;
	if(L!=R){ // check not leaf
		int mid = (L+R)>>1;
		if(node->chatag){ // need to change
			node->lc->chatag = node->chatag;
			node->rc->chatag = node->chatag;
			node->lc->val = node->chatag*(mid-L+1);
			node->rc->val = node->chatag*(R-mid);
			node->lc->mxval = node->chatag;
			node->rc->mxval = node->chatag;
			node->lc->mnval = node->chatag;
			node->rc->mnval = node->chatag;
			node->lc->addtag = node->addtag;
			node->rc->addtag = node->addtag;
		}else{
			node->lc->addtag += node->addtag;
			node->rc->addtag += node->addtag;
		}
		node->lc->val += node->addtag*(mid-L+1);
		node->rc->val += node->addtag*(R-mid);
		node->lc->mxval = node->lc->mxval + node->addtag;
		node->rc->mxval = node->rc->mxval + node->addtag;
		node->lc->mnval = node->lc->mnval + node->addtag;
		node->rc->mnval = node->rc->mnval + node->addtag;
	}
	node->addtag = 0;
	node->chatag = 0;
}

void ADDmodify(Node *node ,int L, int R, int ql, int qr, int d){
	if(ql>R||qr<L)return;
	if(ql<=L&&R<=qr){ // in range
		node->addtag += d;
		node->val += d*(R-L+1);
		node->mxval += d;
		node->mnval += d;
		return;
	}
	push(node,L,R);
	int mid = (L+R) >> 1;
	ADDmodify(node->lc,L,mid,ql,qr,d);
	ADDmodify(node->rc,mid+1,R,ql,qr,d);
	node->pull();
}

void CHAmodify(Node *node ,int L, int R, int ql, int qr, int d){
	if(ql>R||qr<L)return;
	if(ql<=L&&R<=qr){
		node->chatag = d;
		node->addtag = 0; 
		node->val=d*(R-L+1);
		node->mxval=d;
		node->mnval=d;
		return;
	}
	push(node,L,R);
	int mid = (L+R) >> 1;
	CHAmodify(node->lc,L,mid,ql,qr,d);
	CHAmodify(node->rc,mid+1,R,ql,qr,d);
	node->pull();
}

int VALquery(Node *node,int L,int R, int ql,int qr){
	if(ql>R||qr<L)return 0;
	if(ql<=L && R<=qr)return node->val;
	push(node,L,R);
	int mid = (L+R)>>1;
	return VALquery(node->lc,L,mid,ql,qr)+ VALquery(node->rc,mid+1,R,ql,qr);
}

int MAXquery(Node *node,int L,int R, int ql,int qr){
	if(ql>R||qr<L)return 0;
	if(ql<=L && R<=qr)return node->mxval;
	push(node,L,R);
	int mid = (L+R)>>1;
	return max(MAXquery(node->lc,L,mid,ql,qr), MAXquery(node->rc,mid+1,R,ql,qr));
}

int MINquery(Node *node,int L,int R, int ql,int qr){
	if(ql>R||qr<L)return 0;
	if(ql<=L && R<=qr)return node->mnval;
	push(node,L,R);
	int mid = (L+R)>>1;
	return min(MINquery(node->lc,L,mid,ql,qr), MINquery(node->rc,mid+1,R,ql,qr));
}

signed main(){
	io_op
	cin >> N >> Q;
	v.resize(N+1);
	for(int i = 1; i<=N; i++){
		cin >> v[i];
	}
	Node *seg = build(1,N);
	while(Q--){
		int k,l,r,x;cin >> k >> l >> r;
		switch(k){
			case 1:
				cin >> x;
				CHAmodify(seg,1,N,l,r,x);
				break;
			case 2:
				cin >> x;
				ADDmodify(seg,1,N,l,r,x);
				break;
			case 3:
				cout << VALquery(seg,1,N,l,r) << endl;
				break;
			case 4:
				cout << MAXquery(seg,1,N,l,r) << endl;
				break;
		}
	}
	
} 
