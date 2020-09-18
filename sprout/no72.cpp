#include<bits/stdc++.h>
using namespace std;
#define eps 1e-9
vector<vector<double> > V;
int n;
double check(double f){
	double ans= -1e9;
	for(int i = 0; i<n; i++){
		ans=max(ans,V[i][0]*(f-V[i][1])*(f-V[i][1])+V[i][2]);
	}
	return ans;
}

int main(){ 
	int t; cin >> t; while(t--){
		cin >> n;
		vector<double> tmp(3);
		V.resize(n,tmp);
		for(int i = 0; i<n; i++){
			for(int j = 0; j<3; j++)cin >> V[i][j];
		}
		double l=0,r=300;
		double mid1 = (l+r)/2;
		double mid2 = (mid1+r)/2;
		while(l<r-eps){
			if(check(mid1)>check(mid2)+eps) l=mid1;
			else r = mid2;
			mid1 = (l+r)/2;
			mid2 = (mid1+r)/2; 
		}
//		cout << mid1;
		cout << fixed << setprecision(5) << check(mid1) << endl;
		V.clear();
	}
} 
