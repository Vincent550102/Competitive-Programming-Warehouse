#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

struct Node{
	Node *lc,*rc;
	int val;
	Node(){
		lc=rc=NULL;
		val = 0;
	}
	void pull(){
		val = lc->val + rc->val;
	}
};

Node* getNode(Node *node){
	Node* _node = new Node();
	_node->lc = node->lc;
	_node->rc = node->rc;
	_node->val = node->val;
	return _node;
}

Node* build(int L ,int R){
	Node* node = new Node();
	if(L==R){
		node->val = v[L];
		return node;
	}
	int mid = L+R>>1;
	node->lc = build(L,mid);
	node->rc = build(mid+1,R);
	node->pull();
	return node;
}

void modify(Node* node, Node* newnode, int L, int R, int x, int d){
	if(L==R){
		newnode->val += d;
		return;
	}
	int mid = L+R>>1;
	if(x<=mid){
		newnode->lc = getNode(node->lc);
		modify(node->lc,newnode->lc,L,mid,x,d);	
	}else {
		newnode->rc = getNode(node->rc);
		modify(node->rc,newnode->rc,mid+1,R,x,d);	
	}
	newnode->pull();
}

int query(Node* node,int L,int R,int lb,int rb){
	if(L>rb||R<lb)return 0;
	else if(lb<=L && R<=rb)return node->val;
	else{
		int mid = L+R>>1;
		return query(node->lc,L,mid,lb,rb)+query(node->rc,mid+1,R,lb,rb);
	}
}

vector<Node*> history;

int main(){
	cin >> n;
	v.resize(n+1);
	for(int i = 1; i<=n; i++){
		cin >> v[i];
	}
	history.resize(n+1);
	history[0] = build(1,n);
	history[1] = getNode(history[0]);
	modify(history[0],history[1],1,n,2,3);
	cout << query(history[0],1,n,1,4) << endl;
	cout << query(history[1],1,n,1,4);
}
