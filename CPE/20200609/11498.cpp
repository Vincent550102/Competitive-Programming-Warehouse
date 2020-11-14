#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	while(cin >> k&&k){
		int N,M;
		cin >> N >> M;
		for(int i = 0; i<k; i++){
			int x,y;cin >> x >> y;
			if(N==x||M==y)cout << "divisa";
			else if(x>N&&y>M)cout << "NE";
			else if(x>N&&y<M)cout << "SE";
			else if(x<N&&y>M)cout << "NO";
			else if(x<N&&y<M)cout << "SO";
			cout << endl;
		}
	}
} 
