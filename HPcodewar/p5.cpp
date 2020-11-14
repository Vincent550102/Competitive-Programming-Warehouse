#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int cnt = 0;
void dc(int l,int r){
	if(r-l<=2)return;
	else {
		int mid = l+r>>1;
		cnt+=mid;
		dc(l,mid);
		dc(mid+1,r);	
	}
	
}

int main(){
	io_op
	int n;
	cin >> n;
	if(n>3)dc(1,n);
	cout << cnt << endl;
	
}
