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
    int n, s;
    cin >> n >> s;
    vector<int> v(n), prefix(n+1,0);
    int num = 0;
    for(int &x:v)
        cin >> x, num += x;
    if(num<s){
        cout << "-1\n";
        return;
    }
    for(int i = 1; i<n+1; i++){
        prefix[i] = prefix[i-1]+v[i-1];
    }
    int ans = INT_MAX;
/*
    for(int x:prefix){
        cout << x << " ";
    }
    cout << endl;*/

    for(int i = 0; i<n+1; i++){
        int tar = s+prefix[i];
        int lb = i, rb=n;
        while(lb<=rb){
            int mb = lb+rb>>1;
            if(prefix[mb]>tar)rb=mb-1;
            else lb = mb+1;

        }
        //cout << i << " " << rb << endl;
        if(prefix[rb]-prefix[i] == s) ans = min(ans,n-rb+i);
    }
    cout << ans << endl;
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
