#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
#define _ <<" "<<
int main(){
	io_op
	int M,N,k;
	cin >> M >> N >> k;
	map<int,int> MP;
	for(int i = 0; i<N; i++){
		int l,r;cin >>l >> r;
		MP[l-1]++;
		MP[r]--;
	}
	int now = 0;
	bool ok = false;
	int in_id = -1;
	int ans = 0;
	for(auto x:MP){
		now+=x.S;
		if(now>=k&&!ok){
			ok = true;
			in_id = x.F;
		}else if(now<k&&ok){
			ans+=x.F-in_id;
			ok = false;
		}
	}
	
	cout << ans << endl;
	
}
