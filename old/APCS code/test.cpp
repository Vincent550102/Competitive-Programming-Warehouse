#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	while(cin >> N){
		tuple<int,int,int> item[100000];
		bool laze_mark[100000];
		int energe = 0;
		for(int i = 0;i<N;i++){
			int tmp;
			cin >> tmp;
			item[i] = make_tuple(tmp,0,0);
		}
		for(int i = 0; i<N; i++){
			int tmp;
			cin >> tmp;
			get<1>(item[i]) = tmp;
		}
		for(int i = 0;i<N; i++){
			int sum = 0;
			for(int j =0;j<N;j++){
				if(j == i) continue;
				sum += get<0>(item[j]);
			}
			get<2>(item[i]) = sum*get<1>(item[i]);
		}
		int count = N-1;
		while(count--){
			int most_cheap = 1000000;
			int most_cheap_point = -1;
			for(int i = 0;i <N; i++){
				if(laze_mark[i] == true)continue;
				if(most_cheap>get<2>(item[i])){
					most_cheap_point = i;
						most_cheap = get<2>(item[i]);
				}
			}
			laze_mark[most_cheap_point] = true;
			int sum_weight = 0;
			for(int i = 0; i<N; i++){
				if(laze_mark[i] == true)continue;
				sum_weight += get<0>(item[i]);
			}
			energe += sum_weight*get<1>(item[most_cheap_point]);
		}		
		cout << energe;
	}
	
	
	
}
