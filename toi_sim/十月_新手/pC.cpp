#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int main(){
	io_op
	int sleep = 0;
	int S,E,A;
	cin >> S >> E >> A;
	int cnt = 0;
	while(1){
		cnt++;
		sleep++;
		if(S>=E){
			cout << cnt;
			break;
		}
		if(A<=0){
			cout << "unsalable";
			break;
		}
		if(sleep == 9){
			cnt+=1;
			sleep = 0;
			A--;
			continue;
		}
		if(!(cnt%3)){
			S+=S/3;
		}else S+=S/10;
	}
	cout << endl;
	
}
