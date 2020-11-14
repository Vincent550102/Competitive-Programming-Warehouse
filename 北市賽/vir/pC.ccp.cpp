#pragma GCC optimize("O3,unroll-loops")
#pragma loop_opt(on)

#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
#define endl '\n'
#define _ <<" "<<
using ll = long long;
constexpr ll MOD = 1e9+7;
using namespace std;
constexpr int mxN = 1e5+5;
int N,Q;
vector<pii> query;
vector<int> ori_arr;
bool f(vector<int> arr,int num){
	for(int i = num-1; i>=0; i--){
		sort(arr.begin()+query[i].F-1,arr.begin()+query[i].S);
	}
	for(int i = 1; i<N; i++){
		if(arr[i]!=arr[i-1]+1)return 0;
	}
	return 1;
}

signed main(){
	io_op
	cin >> N >> Q;
	query.resize(Q);
	ori_arr.resize(N);
	for(int i = 0; i<N; i++){
		cin >> ori_arr[i];
	}
	for(int i = 0; i<Q; i++){
		cin >> query[i].F >> query[i].S;
	}
	if(!f(ori_arr,Q))cout << "-1\n";
	else{
		int lb=0,rb=Q,mb;
		while(rb>=lb){
			mb=lb+rb>>1;
			if(f(ori_arr,mb))rb=mb-1;
			else lb=mb+1;
		}
		cout << lb << endl;
	}
}
