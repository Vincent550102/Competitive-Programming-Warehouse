#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
struct Node{
	int val,tag;
	Node *lc ,*rc;
	Node(){
		val = tag = 0;
		lc=rc=NULL;
	}
	void pull(){
		val = lc->val+rc->val;
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
	if(L!=R){//check not leaf
		int mid = (L+R)>>1;
		node->lc->tag += node->tag;
		node->rc->tag += node->tag;
		node->lc->val += node->tag*(mid-L+1);
		node->lc->val += node->tag*(R-mid);
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
	cin >> n;
	v.resize(n+1);
	for(int i = 1; i<=n; i++){
		cin >> v[i];
	}
	Node *seg = build(1,n);
	modify(seg,1,n,1,3,5);
	cout << query(seg,1,n,1,3) << endl;
} 
