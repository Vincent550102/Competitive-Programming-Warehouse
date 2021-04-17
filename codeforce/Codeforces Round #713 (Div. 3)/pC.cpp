	#pragma GCC optimize("O3,unroll-loops")
	#pragma loop_opt(on)
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
	#define _ << " " <<
	
	#define coutv(v) for(auto x:v){\
		cout << x << " ";\
	}cout << '\n';
	
	constexpr ll mxN = 1e4;
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
	
	void solver(){
		int cnt[2]; cin >> cnt[0] >> cnt[1];
		string str;
		cin >> str;
		int n = cnt[0]+cnt[1];
		bool flag = true;
		for(int i = 0; i<n; i++){
			if(str[i]!='?'){
				if(str[n-i-1]==str[i]){
					cnt[str[i]-'0']--;
				}else if(str[n-i-1]=='?'){
					str[n-i-1]=str[i];
	//				if(!cnt[str[i]-'0'])flag = 0;
					cnt[str[i]-'0']-=1+(n-i-1<i);
				}else flag = 0;
			}
	//		#define _ <<" "<<
	//		cout << str _ cnt[0] _ cnt[1] _ flag << endl;
		}
		if((n&1)){
			if(str[n/2]=='?'){
	//			if((cnt[0]&1==0 && cnt[1]&1==0) || (cnt[0]&1 && cnt[1]&1)) flag=0;
	//			if{
					if(cnt[0]&1){
						str[n/2]='0';
						cnt[0]--;
					}else{
						str[n/2]='1';
						cnt[1]--;
					}
	//			}
			}
		}
	//	assert(!(cnt[0]<0||cnt[1]<0));
		if(cnt[0]<0||cnt[1]<0||cnt[0]<0||cnt[1]<0||cnt[0]&1||cnt[1]&1)flag = 0;
		for(int i = 0; i<n; i++){
			if(str[i]=='?'){
				str[i]=str[n-i-1]=(cnt[0]?'0':'1');
				cnt[0]?cnt[0]-=2:cnt[1]-=2;
			}
		}
		cout << (flag?str:"-1") << endl;
	}
	
	int main(){
		io_op
		int t;cin >> t;while(t--){ solver(); }
	}
