#include<bits/stdc++.h>

#define pbi pair<bool,int>
#define fir first
#define sec second
using namespace std;


int main(){
	int N;
	int solcnt = 0;
	pbi group[50005];
	cin >> N;
	for(int i = 0; i<N; i++){
		cin >> group[i].sec;
		group[i].fir = false;
	}
	
	for(int i = 0; i<N; i++){
		if(group[i].fir == false){
			solcnt++;
			group[i].fir = true;
			int f = group[i].sec;
			while(group[f].fir == false){
				group[f].fir = true;
				f = group[f].sec;
			}
		}else{
			continue;
		}	
	}
	cout << solcnt << endl;
}
