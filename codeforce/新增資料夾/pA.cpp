#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
#define mk make_pair
using namespace std;
void solve(){
	int a,b;
	cin >> a >> b;
	int ans = abs(b-a)/10;
//	cout << ans << " ";
	ans += abs(b-a)%10!=0;
	cout << ans << endl;
}
int main(){
	io_op
	int t;cin >> t;while(t--){
		solve();
	}
} 
