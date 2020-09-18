#include<bits/stdc++.h>
#define IO_OP ios_base::sync_with_stdio(0);cin.tie(0);
#define F first 
#define S second
#define MK make_pair
using namespace std;
void solve(){
	int n,k;
	cin >> n >> k;
	string a;
	cin >> a;
	int pre_p = -k-1;
	int ans = 0;
	int remain,num;
	bool ok = true;
	if(a=="0"){
		cout << "1" << endl;
		return;
	}
//	cout << ans << endl;
	for(int i = 0; i<n; i++){
		if(a[i]=='1'){
			remain = i-pre_p-1;
			num = 0;
			while(1){
				if((num+1)*(k+1)+k>remain){
					break;
				}
//				cout << num <<" "<<remain<<endl;
				num++;
			}
//			cout << num << endl;
			ans+=num;
			pre_p = i;
//			cout << ans << endl;
		}
	}
	remain = n-pre_p-1+k;
	num = 0;
	
//	cout << remain << endl;
	while(1){
		if((num+1)*(k+1)+k>remain){
			break;
		}
		num++;
	}
//	cout << ans << endl;
	ans+=num;
	cout << ans << endl;
}
int main(){
	IO_OP
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
