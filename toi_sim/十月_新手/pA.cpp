#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int main(){
	io_op
	int N;
	cin >> N;
	int a=N-(N/2000)*200;
	int b=N-(N/1000)*100;
	if(a>b){
		cout <<	b << " 1" << endl;
	}else cout << a << " 0" << endl;
	
}
