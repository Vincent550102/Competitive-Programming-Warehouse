#include<bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e6+5;

struct Node{
	int val;
	Node *lc, *rc;
	Node(){
		val = INT_MAX;
		lc = rc = NULL;
	}
	void pull(){
		val = min(lc->val, rc->val);
	}
};

int v[mxN];

Node *build(int L, int R){
	Node *node = new Node();
	if(L==R){
		node->val=v[L];
		return node;
	}
	int mid = L+R>>1;
	node->lc=build(L,mid);
	node->rc=build(mid+1,R);
	node->pull();
	return node;
}

int query(Node *node, int L, int R, int lb, int rb){
	if(L>rb||R<lb) return INT_MAX;
	if(lb<=L&&R<=rb) return node->val;
	int mid = L+R>>1;
	return min(query(node->lc, L, mid, lb, rb), query(node->rc, mid+1, R, lb, rb));
}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> v[i];
		v[i]++;
	}
	Node *sgt = build(1, n);
	for(int i = 0; i<n; i++){
		int l,r;cin >> l >> r;
		cout << query(sgt,1,n,l,r) << endl;
	}
}
