#pragma GCC target("fma,avx")
#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
#define endl '\n'
#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define _ <<' '<<
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
#define Lb(x) (x&-x)
#define mod 10000019
#define int ll
struct BIT{
    int sz;
    vector<int> v;
    vector<int> num;
    void modify(int x, int d){
        while(x<=sz){
            v[x]+=d;
//            v[x]%=mod;
            x+=Lb(x);
        }
    }
    int query(int x){
        int sum = 0;
        while(x){
            //cout << x << endl;
            sum+=v[x];
//            sum%=mod;
            x-=Lb(x);
        }
        return sum;
    }
};

signed main(){
    FAST
    BIT bit1;
    BIT bit2;
    int n;cin >> n;
    bit1.sz = n;
    bit1.v.resize(n+3,0);
    bit2.sz = n;
    bit2.v.resize(n+3,0);
	vector<int> vec(n);
	for(int i =0 ; i<n; i++){
    	cin >> vec[i];
	}
	vector<int> tmp = vec;
	sort(tmp.begin(),tmp.end());
	tmp.resize(unique(tmp.begin(),tmp.end()) - tmp.begin());
	int ans = 0;
	for(int i = 0; i<n; i++){
		vec[i] = lower_bound(tmp.begin(),tmp.end(),vec[i])-tmp.begin()+1;
	}
//	for(int i = 0; i<n; i++)cout << vec[i];
	for(int i = 0; i<n; i++){
		ans += ((bit1.query(n)% mod -bit1.query(vec[i]) % mod )+(tmp[vec[i] - 1]*(i-bit2.query(vec[i])))) % mod;
//		cout << bit1.query(n) -bit1.query(vec[i]) << " "<< i-bit2.query(vec[i]) << endl;
		bit1.modify(vec[i],tmp[vec[i] - 1]);
		bit2.modify(vec[i],1);
	}
	cout << (ans + mod) % mod << endl;
    
}
