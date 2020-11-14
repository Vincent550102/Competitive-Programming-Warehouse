#include<bits/stdc++.h>
using namespace std;

struct Node{
	int height;
	vector<int> child_node;
}node[100000];

int found_high(int whi_node){
	if(node[whi_node].child_node.empty()){
		return 0;
	}else{
		int len = node[whi_node].child_node.size();
		int maxhei = -1;
		for(int i = 0; i<len; i++){
			maxhei = max(maxhei , found_high( node[whi_node].child_node[i] ) + 1);
		}
		return maxhei;
	}
}

int main(){
	int n;
	cin.tie(0);
	cin >> n;
	for(int i = 1; i<=n; i++){
		int num;
		cin >> num;
		for(int j =1; j<=num; j++){
			int relation;
			cin >> relation;
			node[i].child_node.push_back(relation);
		}
	}
	int maxh = -1;
	int top = 0;
	int sum = 0;
	for(int i = 1; i<=n; i++){
		int ne = found_high(i);
		if(ne > maxh){
			maxh = ne;
			top = i;
		}
		sum += ne; 
	}
	
	cout << top << endl << sum;
}



