#include<iostream>
using namespace std;
int main(){
	int H,M;
	cin >> H >> M;
	int t = 60*H+M;
	if(860 <= t && t<= 1000){
		cout << "YES";
	}else{
		cout << "NO";
	}
	cout << endl;
} 
