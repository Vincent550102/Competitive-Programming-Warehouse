#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using pii = pair<int,int>;
using piii = pair<int,pii>;
using ll = long long;
//#define int ll
#define F first
#define S second
#define All(x) x.begin(),x.end()
#define Vi vector<int>
#define Vl vector<ll>
#define Pb push_back
#define Eb emplace_back
#define endl '\n'

#define coutv(v) for(auto x:v){\
	cout << x << " ";\
}cout << '\n';

constexpr ll mxN = 1e10;
constexpr ll MOD = 1e9+7;

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

int prime[maxN],cnt;
void gets_primes(int n)
{
   memset(st,false,sizeof st);
   cnt=0;
   for(int i=2;i<=n;i++)
   {
        if(!st[i])prime[cnt++]=i;
        for(int j=0;prime[j]*i<=n;j++)
        {
            st[prime[j]*i]=true;
            if(i%prime[j]==0)break;
        }
   }
}

void solver(){
	ll n;
	cin >> n;
	map<ll,int> prime_crack;
	for(ll i = 2; i<=sqrt(n); i++){
		if(!(n%i)){
			prime_crack[i]++;
			n/=i;
		}
	}
	for(auto x:prime_crack){
		cout << x.F << " " <<x.S <<endl;
	}
}

int main(){
	io_op
	gets_primes(mxN);
	int T;cin >> T;while(T--){ solver(); }
}
