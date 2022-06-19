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
    vector<int> v(4);
    int ans = 0;
    for(int i = 0; i<4; i++){
        cin >> v[i];
    }
    for(int i = 1; i<4; i++){
        if(v[i]>v[0]) ans++;
    }
    cout <<ans << endl;

}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
