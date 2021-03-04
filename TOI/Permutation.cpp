#include<bits/stdc++.h>
using namespace std;
int main(){
	int D;
	string S;
	cin >> D >> S;
	string tar = S;
	#define All(x) x.begin(),x.end()
	sort(All(S));
	int ans = 0;
	while(next_permutation(All(S))){
		ans++;
		ans%=D;
		if(tar==S)break;
	}
	cout << ans << endl;
} 
