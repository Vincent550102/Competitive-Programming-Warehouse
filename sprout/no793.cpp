#include<bits/stdc++.h>
using namespace std;
const long long p = 1e9+7;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long n,k,q;
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cin >> n >> k >> q;	
	unordered_map<long long,long long> pw;//密碼本 
	map<long long,long long> MP;//出現幾次 
	vector<long long> ht(n);//差分 
	vector<long long> v(n);//原陣列 
	for(int i = 0; i<n; i++){	
		cin >> v[i];
	}
	if(k==1){
		int l,r;
		for(int i = 0; i<q; i++)
			cin >> l >> r;
		for(int i = 0; i<q; i++)
			cout << "1";
		cout << endl;
		return 0;
	}
	
	for(int i = 0; i<n; i++){
		if(!pw.count(v[i])){
			pw[v[i]]=rand()%p;
			MP[v[i]] = 0;
		}
	}
	
	ht[0]=pw[v[0]];
	MP[v[0]] = 1;
	for(int i = 1; i<n; i++){
		if(MP[v[i]]!=k-1){
			MP[v[i]]++;
			ht[i] = (ht[i-1] + pw[v[i]])%p;
		}else{
			MP[v[i]] = 0;
			ht[i] = (ht[i-1] - ((k-1)*pw[v[i]])%p+p)%p;
		}
	}
//	for(int x:ht){
//		cout << x << " ";
//	}
	
	while(q--){
		int l ,r;
		cin >> l >>r;
		l--;r--;
		if(ht[r]-((l!=0)?ht[l-1]:0)==0){
			cout << '1';
		}else{
			cout << '0';
		}
	}
	cout << endl;
}
