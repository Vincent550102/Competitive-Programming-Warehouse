#include<bits/stdc++.h>
using namespace std;

int read(){
	char q;cin >> q;
	if(q=='f'){
		int x = read();
		return 2*x-1;
	}else if(q=='g'){
		int x = read();
		int y = read();
		return x+2*y-3;
	}else{
		return q - '0';
	}
}

int main(){
	cout << read() << endl;
} 
