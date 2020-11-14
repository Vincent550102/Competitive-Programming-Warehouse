#include<bits/stdc++.h>
#define IL(X) ((X)*2+1)
#define IR(X) ((X)*2+2)
#define N 4555555
using namespace std;
int a[N] = {1,2,3,4,5,6,7,8,9};
struct node{
	int sum;
}arr[N*4];

node pull(node x,node y){
	node tmp;
	tmp.sum = x.sum + y.sum;
	return tmp;
}

void build(int L,int R, int id){
	if(L == R){
		arr[id].sum = a[L];
		return ;
	}
	int M = (L+R)/2;
	build(L,M,IL(id));
	build(M+1,R,IR(id));
	arr[id] = pull(arr[IL(id)],arr[IR(id)]);
}

node Query(int l,int r,int L,int R,int id){
	if(l == L&& r == R) return arr[id];
	int M = (L+R)/2;
	if(r <= M)return Query(1,r,L,M,IL(id));
	if(M < l) return Query(l,r,M+1,R,IR*id);
	return pull(Query(l,M,L,M,IL(id)),Query(M+1,r,M+1,R,IR(id)));
}
int main(){
	
} 
