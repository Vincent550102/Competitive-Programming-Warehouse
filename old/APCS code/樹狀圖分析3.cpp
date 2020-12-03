#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct n{
	vector<int> child;
	ll parent = -1;
	ll height = 0;
	bool isleaf = false;
};
n node[100005];

ll found_root(ll node_num){
	for(ll i = 1 ; i <= node_num; i++){
		if(node[i].parent == -1) return i;
	}
}

ll count_height(ll node_no){
	if(node[node_no].isleaf == true){
		node[node_no].height = 0;
		return 0;
	}else{
		for(auto x : node[node_no].child){
			count_height(x);
			node[node_no].height = max( node[node_no].height , node[x].height + 1 );
		}
	}
}


int main(){
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; i++){
		ll k;
		cin >> k;
		node[i].child.resize(k+4);
		for(ll j = 0; j<k; j++){
			cin >> node[i].child[j];
			node[node[i].child[j]].parent = i;
		}
		if(k == 0){
			node[i].isleaf = true;
		}
	}
	ll roof_node = found_root(n);
	count_height(roof_node);
	ll sum_height = 0;
	for(auto x : node){
		sum_height += x.height; 
	}
	cout << roof_node <<endl<< sum_height;
}
