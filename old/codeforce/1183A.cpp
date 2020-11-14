#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool isinterest(int x){
	stringstream trans;
	string strNum;
	trans << x;
	trans >> strNum;
	int len = strNum.size();
	int sum = 0;
	for(int i = 0; i <len; i++){
		sum += strNum[i] - '0';
	}
	if(sum%4 == 0) return true;
	else return false;
}


int main(){
	ll a;
	cin >> a;
	while(!isinterest(a)){
		a++;
	}
	cout << a;
	
}
