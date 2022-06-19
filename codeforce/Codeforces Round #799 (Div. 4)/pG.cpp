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
    int n, k;cin >> n >> k;
    vector<int> v(n), chk(n);
    for(int i = 0; i<n; i++)
        cin >> v[i];


    for(int i = 0; i<n-1; i++)
        chk[i] = 2*v[i+1] > v[i];

    int ans = 0, winnum = 0;
    for(int i = 0; i<k; i++)
        winnum += chk[i];

    ans += winnum==k;
    for(int i = k; i<n-1; i++){
        winnum+=chk[i];
        winnum-=chk[i-k];
        ans += winnum==k;
    }
    cout << ans << endl;
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
