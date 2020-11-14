#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int mxN = 1e3+5;
int n;
vector<int> v[mxN];
int proceed[mxN];
int now[mxN];
void init(){
	for(int i = 0; i<n; i++){
		v[i].clear();
		now[i]=i+1;
		proceed[i]=-1;
	}
}
void roll(){
	int tmp = now[0];
	for(int i = 0; i<n-1; i++){
		now[i]=now[i+1];
	}
	now[n-1]=tmp;
}

int main(){
	io_op
	int t;cin >> t;while(t--){
		cin >> n;
		init();
		for(int i = 0;i<n; i++){
			v[i].resize(n);
			for(int j = 0; j<n; j++){
				cin >> v[i][j];
			}
		}
		int cnt = -1;
		bool ok = 0;
		while(!ok){
			ok = 1;
			cnt++;
			for(int i = 0;i<n; i++){
				if(proceed[i]<n-1&&v[i][proceed[i]+1]==now[i])proceed[i]++;
			}
			for(int i = 0; i<n; i++){
				if(proceed[i]!=n-1){
					roll();
					ok=0;
					break;
				}
			}
		}
		cout << cnt << endl;
	}
}
