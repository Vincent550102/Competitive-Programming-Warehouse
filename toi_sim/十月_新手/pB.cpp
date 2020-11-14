#include<bits/stdc++.h>
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int main(){
	io_op
	int N;string P;
	cin >> N >> P;
	int len = P.size();
	int max_id = 0,max_num = INT_MIN;
	int cnt = 0;
	while(1){
		cnt++;
		int num = 0;
		int start = len-(cnt-1)*N-1;
		int i;
		for(i = start; i>=0&&i>=start-N+1;i--){
//			cout << i << " ";
			num+=P[i]-'0';
		}
		if(num>=max_num){
			max_num = num;
			max_id = cnt;
		}
//		cout << num << endl;
		if(i<0)break;
	}
	cout <<max_id << " " << max_num << endl;
	
}
