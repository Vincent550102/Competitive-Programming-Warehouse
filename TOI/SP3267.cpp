#include<bits/stdc++.h>
using namespace std;
#define All(x) x.begin(),x.end()
constexpr int mxA = 1e6+5, mxN = 3e4+5;
int cnt[mxA] = {0};
int ans=0;
int K;

struct Q{
	int l,r;
	int qid,bid;
	void init(int _qid){
		qid=_qid;
		bid=l/K;
	}
};

void add(int x){
	if(!cnt[x]) ans++;
	cnt[x]++;
}

void del(int x){
	cnt[x]--;
	if(!cnt[x]) ans--;
}

int main(){
	int n; cin >> n;
	K=sqrt(n);
	vector<int> v(n);
	for(int &x:v){
		cin >> x;
	}
	int q; cin >> q;
	vector<Q> Qv(q);
	vector<int> anslist(q);
	for(int i = 0; i<q; i++){
		cin >> Qv[i].l >> Qv[i].r;Qv[i].l--, Qv[i].r--;
		
		Qv[i].init(i);
	}
	sort(All(Qv), [](Q a, Q b){
		return a.bid==b.bid?a.r<b.r:a.bid<b.bid;	
	});
	
	int lb=0,rb=-1;
	for(Q Qi:Qv){
		while(Qi.l<lb){
			lb--;
			add(v[lb]);
		}
		while(Qi.l>lb){
			del(v[lb]);
			lb++;
		}
		while(Qi.r<rb){
			del(v[rb]);
			rb--;
		}
		while(Qi.r>rb){
			rb++;
			add(v[rb]);
		}
		anslist[Qi.qid]=ans;
	}
	for(int x:anslist){
		cout << x << endl;
	}
}
