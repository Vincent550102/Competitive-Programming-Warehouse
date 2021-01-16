#include<bits/stdc++.h>
using namespace std;

#define All(x) x.begin(),x.end()
#define uni(v) v.resize(unique(All(v))-v.begin()) 

int main(){
	int n;
	while(cin >> n){
		vector<int> v(n);
		for(int &x:v){
			cin >> x;
		}
		uni(v);
		for(int x:v){
			cout << x << " ";
		}
		cout << endl;
	}
}
