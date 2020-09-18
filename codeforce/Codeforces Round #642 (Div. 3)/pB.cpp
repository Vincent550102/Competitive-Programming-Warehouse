#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
#define ALL(x) x.begin(),x.end()
int main(){
	FAST
	int t;cin >> t;while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>a(n),b(n);
		for(int i = 0; i<n; i++)cin >> a[i];
		for(int i = 0; i<n; i++)cin >> b[i];
		sort(ALL(a));
		sort(ALL(b));
		int sum = 0;
		for(int i = 0; i<k; i++){
			if(a[i]<b[n-i-1])swap(a[i],b[n-i-1]);
			else break;
		}
		for(int x:a)sum+=x;
		cout << sum << endl;
	}
}
