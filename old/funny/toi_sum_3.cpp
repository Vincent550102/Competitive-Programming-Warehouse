#include<bits/stdc++.h>
#define mk make_pair
#define s second
#define f first
using namespace std;

bool cmp(pair<int ,int> a,pair<int ,int> b){
	if(a.s > b.s){
		return a>b;
	}else if(a.s == b.s &&a.f < b.f){
		return a<b;
	}
	return a<b;
}
int main(){
	int N,M;
	cin >> N >> M;
	vector<pair<int ,int> >vec{mk(0,0)};
	vec.resize(N);
	for(int i = 0; i<N; i++){
		vec[i].f = i;
	}
	for(int i = 0; i<M; i++){	
		int no,po;
		cin >> no >>po;
		vec[no] = mk(no,vec[no].s+po);
	}
	
	sort(vec.begin(),vec.end(),cmp);
	
	for(auto x:vec){
		cout <<x.f << " " <<x.s <<endl;
	}
	
}
