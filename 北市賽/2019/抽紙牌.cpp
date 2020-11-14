#include<bits/stdc++.h>
#define io_OP ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define pci pair<char,int>
#define F first
#define S second

bool comp(pci a,pci b){
	if(a.S==b.S)return a.F>b.F;
	else return a.S>b.S;
}

int main(){
	io_OP
	int n;
	cin >> n;
	vector<pci> v(n);
	for(int i = 0; i<n; i++){
		string color,num;
		cin >> color >> num;
		v[i]={color[0],(int)stoi(num)};
	}
	sort(v.begin(),v.end(),comp);
	int m;cin >> m;m--;
	cout << v[m].F << " " << v[m].S;
}
