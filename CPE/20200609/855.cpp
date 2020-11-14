#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

#define Ft first 
#define Se second

int main(){
	int t;cin >> t;while(t--){
		int S,A,F;cin >> S >>A >> F;
		double sumS=0,sumA=0;
		vector<int> x(F),y(F);
		for(int i = 0; i<F; i++){
			cin >> x[i] >> y[i];
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		cout << "(Street: "<<x[(F-1)/2] <<", Avenue: "<<y[(F-1)/2] <<")\n";
	}
}
