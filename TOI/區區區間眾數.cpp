#include<bits/stdc++.h>
using namespace std;
constexpr int mxN = 1e5+5;
#define All(x) x.begin(),x.end()
int k, max_num=-1;
int app[mxN]={0}, cnt[mxN]={0};

struct Q{
	int l,r,qid,bid;
};

void add(int x){
	int num = ++app[x];
	cnt[num-1]--;
	cnt[num]++;
	max_num=max(max_num,num);
}

void del(int x){
	int num = --app[x];
	cnt[num+1]--;
	cnt[num]++;
	if(!cnt[max_num]){
		max_num--;
	}
}


int main(){
	int n,q;cin >> n >> q;
	k = sqrt(n);
	vector<int> v(n);
	vector<Q> Qv(q);
	for(int &x:v){
		cin >> x;
	}
	for(int i = 0; i<q; i++){
		int L,R;cin >> L >> R;L--;R--;
		Qv[i].l = L;
		Qv[i].r = R;
		Qv[i].qid = i;
		Qv[i].bid = L/k;
	}
	sort(All(Qv),[=](Q a, Q b){
		return a.bid==b.bid?a.r<b.r:a.bid<b.bid;
	});
	int lb=0,rb=-1;
	vector<int> ans(q);
//	cout << "---\n";
//	for(auto x:Qv){
//		cout << x.l << " " << x.r<<endl;
//	}
	#define _ <<" "<<
	for(int i = 0; i<q; i++){
		while(rb<Qv[i].r){
			rb++;
			add(v[rb]);
		}
		while(rb>Qv[i].r){
			del(v[rb]);
			rb--;
		}
		while(lb<Qv[i].l){
			del(v[lb]);
			lb++;
		}
		while(lb>Qv[i].l){
			lb--;
			add(v[lb]);
		}
//		cout << lb _ rb << endl;
//		cerr << i;
		ans[Qv[i].qid]=max_num;
//		cerr << i;
	}
	for(int a:ans){
		cout << a << endl; 
	}
} 
