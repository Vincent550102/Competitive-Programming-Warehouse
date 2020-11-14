#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check_cant_be_sqrt(ll P){
	bool flag = true;
	
	for(ll i = 2; i<=P-1; i++){
		if(P%i==0)flag = false;
	}
	if(flag) return true;
	else return false;
}

bool cmp(ll a,ll b){
	if(a>b){
		return a>b;
	}else{
		return a<b;
	}
}

int main(){
	ll N;
	cin >>N;
	vector<ll> may_P;
	for(ll i = 2; i<N/2+1; i++){
		if(N%i == 0){
			if(check_cant_be_sqrt(i)){
				may_P.push_back(i);
			}
//			if(check_cant_be_sqrt(N/i)){
//				may_P.emplace_back(N/i);
//			}
//			
		}
	}
	
	sort(may_P.begin(),may_P.end(),cmp);
	int len = may_P.size();
	for(int i = 0; i<len ;i++){
		cout << may_P[i]<<endl;
	}
}
