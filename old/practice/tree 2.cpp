#include<bits/stdc++.h>

using namespace std;

void build_tree(int arr[], int tree[], int node, int start, int end){
	if(start == end){
		tree[node] = arr[start];
	}else{
		int mid = (start+end)/2;
		int left_node  = node *2+1;
		int right_node = node *2+2;
		build_tree(arr,tree,left_node,start,mid);
		build_tree(arr,tree,right_node,mid+1,end);
		tree[node] = tree[left_node] + tree[right_node];
	}
}

void updata_tree(int arr[],int tree[],int node,int start,int end,int idx,int val){
	if(start == end){
		arr[idx] = val;
		tree[node] = val;
	}else{
		int mid = (start+end)/2;
		int left_node = node *2+1;
		int right_node = node *2+2;
		if(idx>=start && idx<=mid){
			updata_tree(arr,tree,left_node,start,mid,idx,val);
		}else{
			updata_tree(arr,tree,right_node,mid+1,end,idx,val);
		}
		tree[node] = tree[left_node] + tree[right_node];
	}
}

int query_tree(int arr[],int tree[],int node,int start,int end,int L,int R){
	if(R<start ||L>end){
		return 0;
	}else if(L<=start && end<=R){
		return tree[node];
	}else if(start == end){
		return tree[node];
	}else{
		int mid = (start+end)/2;
		int left_node  = node*2+1;
		int right_node = node*2+2;
		int sum_left  = query_tree(arr,tree,left_node,start,mid,L,R);
		int sum_right = query_tree(arr,tree,right_node,mid+1,end,L,R);
		return sum_left+sum_right;
	}
	
	
	
}

int main(){
	int arr[]= {1,3,5,7,9,11};	
	int len = 6;
	int tree[1000] ={0};
	build_tree(arr,tree,0,0,len-1);
	for(int i = 0; i<15; i++){
		cout << tree[i] << endl;
	}
	updata_tree(arr,tree,0,0,len-1,4,6);
	cout << endl << endl;
	for(int i = 0; i<15; i++){
		cout << tree[i] << endl;
	}
	cout << endl << endl;
	cout << query_tree(arr,tree,0,0,len-1,2,5);
}
