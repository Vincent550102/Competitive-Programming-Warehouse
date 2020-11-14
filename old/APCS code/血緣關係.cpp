#include<bits/stdc++.h>
using namespace std;
struct Node{
	int m_parent;
	int m_indegree;
	int m_max_distance[2];
};

int main(){
	int N;
	Node node[100000];
	while(cin >> N){
		int max_distance = -1;
		for(int i = 0; i < N; i++){
			node[i] = {-1,0,{}};
		}
		
		for(int i = 0; i< N-1; i++){
			int parent,child;
			cin >> parent>>child;
			
			node[child].m_parent = parent;
			node[parent].m_indegree++;
		}
		
		queue<int> leave;
		
		for(int i = 0; i<N; i++){
			if(node[i].m_indegree == 0){
				leave.push(i);
			}
		}
		
		while(!leave.empty()){
			int leaf =leave.front();
			leave.pop();
			int parent = node[leaf].m_parent;
			
			if(parent == -1) continue;
			int value = node[leaf].m_max_distance[0]+1;
			if(value > node[parent].m_max_distance[0]){
				node[parent].m_max_distance[1] = node[parent].m_max_distance[0];
				node[parent].m_max_distance[0] = value;
			}else if(value > node[parent].m_max_distance[1]){
				node[parent].m_max_distance[1] = value;
			}
			
			node[parent].m_indegree--;
			if(node[parent].m_indegree == 0){
				leave.push(parent);
			}
			int distance = node[parent].m_max_distance[0] + node[parent].m_max_distance[1];
			if(max_distance<distance){
				max_distance = distance;
			}
		}
		cout << max_distance<<'\n';
	}
}
