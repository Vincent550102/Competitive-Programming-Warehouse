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
    vector<int> v;
    array<int, 10> dig;
    dig.fill(0);
    for(int i = 0; i<n; i++){
        int tmp; cin >> tmp;
        dig[tmp%10]++;
        if(dig[tmp%10]<=3) v.push_back(tmp%10);
    }
    int sz = v.size();
    int ans = 0;
    for(int i = 0; i<sz; i++){
        for(int j = i+1; j<sz; j++){
            for(int k = j+1; k<sz; k++){
                if((v[i]+v[j]+v[k])%10 == 3) ans=1;
            }
        }
    }
    cout << (ans?"YES":"NO") << endl;
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
