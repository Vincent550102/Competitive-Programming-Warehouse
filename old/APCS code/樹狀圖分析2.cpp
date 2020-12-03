#include<bits/stdc++.h>
#define vec vector<int>
#define ll long long
using namespace std;

struct Node{
	ll height;
	ll parent;
	bool isleaf;
	vec child;
}node[100005];

ll height_count(ll node_id){
	if(node[node_id].isleaf == true){
		node[node_id].height = 0;
	}else{
		ll max_child_height = -1;
		ll len  = node[node_id].child.size();
		for(ll i = 0 ; i< len ; i++){
			max_child_height = max(max_child_height,height_count( node[node_id].child[i] )+ 1  );
		}
		node[node_id].height = max_child_height;
	}
	return node[node_id].height;
}


int main(){
	int N;
	while(cin >> N){
		
		for(ll i = 1; i<=N; i++){
			node[i].parent = 0;
		}
		
		for(ll i = 1; i<=N; i++){
			ll child_num;
			cin >> child_num;
			if(child_num == 0){
				node[i].isleaf = true;
			}
			while(child_num--){
				ll chi;
				cin >> chi;
				node[i].child.emplace_back(chi);
				node[chi].parent = i;
			}
		}
		
		int top_node = 0;
		for(ll i = 1; i<=N; i++){
			if(node[i].parent == 0)
				top_node = i;
		}
		
		height_count(top_node);
		ll sum_node_height = 0;
		for(ll i = 1; i<=N; i++){
			sum_node_height += node[i].height;
		}
		cout << top_node<<'\n';
		cout << sum_node_height<<'\n';
		
	}
}
