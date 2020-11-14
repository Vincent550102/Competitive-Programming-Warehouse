#include<bits/stdc++.h>
#define ll long long int

//要加以重製即可AC 
using namespace std;

struct n{
	ll parent = -1;
	vector<int> child;
	pair<int,int> relation;
}node[100005];

int max_path = -1;

int write_relation(int node_no){
	if(node[node_no].child.empty()){
		return 0;
	}else{
		for(auto x : node[node_no].child){
			write_relation(x);
			ll value = node[x].relation.first + 1; 
			if(value > node[node_no].relation.first){
				node[node_no].relation.second = node[node_no].relation.first;
				node[node_no].relation.first = value;
			}else if(value > node[node_no].relation.second){
				node[node_no].relation.second = value;
			}
		}
		max_path = max(max_path , node[node_no].relation.first+node[node_no].relation.second);
	}
}

int main(){
	ll n;
	
	while(cin >> n){
		int N = n;
		n--;
		while(n--){
			ll childn,parentn;
			cin >> parentn >> childn;
			node[parentn].child.emplace_back(childn);
			node[childn].parent = parentn;		
		}
		
		int root_node;
		
		for(int i = 0; i < N; i++){
			if(node[i].parent == -1) root_node = i;
		}
		write_relation(root_node);
		
		
		cout << max_path << endl;	
		max_path = -1;	
	}

}
