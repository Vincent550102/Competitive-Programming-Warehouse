#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int fan_list[100005] = {};
bool visit[100005];

int main(){
	ll N,M;
	cin >> N >> M;
	for(int i = 0; i<N+4; i++){
		visit[i] = false;
	}
	
	for(int i = 0; i<M; i++){
		int no,cost;
		cin >> no >> cost;
		fan_list[no] += cost;
	} 
	
	for(int i = N-1; i>=0; i--){
		int max_p = -1;
		int max_id = 0;
		for(int j = N-1; j>=0; j--){
			if(visit[j] == true)continue;
			if(max_p <= fan_list[j]){
				max_p = fan_list[j];
				max_id = j;
			}
		}
		visit[max_id] = true;
		cout << max_id << " " << max_p << endl;
	}
	
}
