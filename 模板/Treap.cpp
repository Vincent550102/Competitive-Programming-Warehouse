#include<bits/stdc++.h>
using namespace std;

struct Treap{
	Treap *lc,*rc;
	int pri,key;
	//pri: key:
	Treap() {}
	Treap(int _key):
		lc(NULL),rc(NULL),pri(rand()),key(_key);
};

Treap* merge(Treap *a,Treap *b){
	if(!a || !b) return a?a:b;
	if(a->pri > b->pri){
		a->rc = merge(a->rc,b);
		return a;
	}else{
		b->lc = merge(a,b->lc);
		return b;
	}
}

void split(Treap *t, int k, Treap *&a, Treap *&b){// <k for a ; >=k for b
	if(!t)a=b=NULL;
	else if(t->key <= k){
		a = t;
		split(t->rc,k,a->rc,b);
	}else{
		b = t;
		split(t->lc,k,a,b->lc);
	}
}

Treap* insert(Treap *t,int k){
	Treap *a,*b;
	split(t,k,a,b);
	return merge(merge(a,new Treap(k)),b);
}

Treap* remove(Treap *t,int k){
	Treap *a,*b,*c;
	split(t, k - 1, a, b);
	split(b, k, b, c);
	return merge(a,c);
}

int main(){
	
}
