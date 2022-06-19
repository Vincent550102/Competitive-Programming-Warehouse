#include<bits/stdc++.h>
using namespace std;
#define io_op ios_base::sync_with_stdio(0);

/*
ll pow_mod(int n, int p){
	int rESULt = 1;
	while(p){
		if(p&1) rESULt=(rESULt * n)%MOD;
		n = (n*n)%MOD;
		p>>=1;
	}
	return rESULt;
}
*/

void solver(){
    int n;cin >> n;
    map<int,int> MP;
    for(int i = 0; i<n; i++){
        int tmp; cin >> tmp;
        MP[tmp]++;
    }
    int num = 0;
    for(auto v:MP){
        if(v.second>1) num+=v.second-1;
    }
    if(num%2)
        cout << n-num-1;
    else
        cout << n-num;
    cout << endl;

}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
