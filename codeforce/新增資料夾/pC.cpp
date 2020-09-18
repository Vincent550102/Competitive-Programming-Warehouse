#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
#define mk make_pair
using namespace std;
void solve(){
	int n,x,y;
	cin >> n >> x >> y;
	n-=2;
	int d=y-x;
	int mid_num=-1;
	for(int i=1; i<=d; i++){
		if(!(d%i) and n>=d/i)mid_num=i;
//		if(i==(d-1)and !(mid_num+1))mid_num
	}
	d = (y-x)/mid_num;
	for(int i = x+d; i<y,n>0; i+=d){
		cout << i <<" ";
		n--;
	}
	for(int i = x-d; i>0,n>0; i-=d){
		cout << i << " ";
		n--;
	}
	for(int i = y+d; n>0; i+=d){
		cout << i << " ";
		n--;
	}
	cout << x << " " << y << endl;
	
}
int main(){
	io_op
	int t;cin >> t;while(t--){
		solve();
	}
} 
