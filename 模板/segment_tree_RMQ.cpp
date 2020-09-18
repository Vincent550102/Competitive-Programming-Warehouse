#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
struct Node{
	int val;
	Node *lc ,*rc;
	Node(){
		val = 0;
		lc=rc=NULL;
	}
	void pull(){
		val = max(lc->val,rc->val);
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

void modify(Node *node ,int L, int R, int i, int d){
	if(L==R){
		node->val += d;
		return;
	}
	int mid = (L+R) >> 1;
	if(i<=mid){
		modify(node->lc,L,mid,i,d);
	}else{
		modify(node->rc,mid+1,R,i,d);
	}
	node->pull();
}

int query(Node *node,int L,int R, int ql,int qr){
	if(ql>R||qr<L)return 0;
	if(ql<=L && R<=qr)return node->val;
	int mid = (L+R)>>1;
	return max(query(node->lc,L,mid,ql,qr),query(node->rc,mid+1,R,ql,qr));
}

int main(){
	
	cin >> n;
	v.resize(n+1);
	for(int i = 1; i<=n; i++){
		cin >> v[i];
	}
	
	cout << query(seg,1,n,1,3) << endl;
} 
