#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v(n);
bool f(int d){ // 確認這樣的基地 
	int cnt = 0;
	for(int i = 0; i<n; i++){
		
//		cout <<" "<< i << " ";
		cnt++;
		if(cnt>k)return false;
		long long aim = v[i];
		aim+=d;
		
		for(int j = i; j<n; j++){
			if(v[j]>aim){
				i = j-1;
//				cout << i << " " << j << endl;;
				break;
			}
			if(j==n-1)i=j;
//			cout << i << " ";
		}
	}
	return true;
}

int main(){
	while(cin >> n >> k){
		v.resize(n);
		for(int i = 0; i<n; i++)cin >> v[i];
		sort(v.begin(),v.end());
		int l = 1,r = 1e9;
//		cout << f(1) << f(2) << f(3) << f(4) << f(5);
		while(l<=r){
			int mid = (l+r)/2;
//			cout << l << " " <<r << " " << f(mid)<< endl;
			if(f(mid)) r = mid-1;
			else l = mid+1;
//			cout << endl;
		}
//		cout << endl;
		cout << l << endl;
		v.clear();
	}
}
