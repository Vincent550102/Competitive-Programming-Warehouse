#include<bits/stdc++.h>
using namespace std;
#define io_op ios_base::sync_with_stdio(0);

/*
ll pow_mod(int n, int p){
	int rESULt = 1;
	while(p){
		if(p&1) rESULt=(rESULt * n)%MOD;
		n = (n*n)%MOD;
		p>>=1;
	}
	return rESULt;
}
*/

void solver(){
    string s;
    array<int, 8> arr;
    array<int, 8> place;
    fill(arr.begin(), arr.end(), 0);
    fill(place.begin(), place.end(), 0);
    for(int i = 0; i<8; i++){
        arr[i] = 0;
        cin >> s;
        int cnt = 0;
        for(char c:s){
            arr[i]+= c=='#';
            if(c=='#')
                place[i]=cnt;
            cnt++;
        }
    }
    for(int i = 1; i<7; i++){
        if(arr[i]==1&&arr[i-1]==2&&arr[i+1]==2){
            cout << i+1 << " " << place[i]+1 << endl;
        }
    }
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
