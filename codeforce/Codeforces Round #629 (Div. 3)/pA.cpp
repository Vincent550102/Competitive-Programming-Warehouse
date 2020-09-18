#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin >> n;while(n--){
		int a,b;cin >> a >> b;
		if(!(a%b)){
			cout << "0\n";
		}else{
			cout << ((a/b)+1)*b-a << endl;
		}
	}
} 
