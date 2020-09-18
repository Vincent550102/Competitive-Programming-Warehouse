#include<bits/stdc++.h>
#define X first
#define Y second
#define _ << " " << 
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<pair<int,int> > Pt(n);
	for(int i =0 ; i<n; i++){
		int a,b;
		cin >> a >>b;
		Pt[i] = make_pair(a,b);
	}
	int r = 0,l = 0,back = 0;
	for(int i = 1; i<n; i++){
		int dx = Pt[i-1].X-Pt[i].X;
		int dy = Pt[i-1].Y-Pt[i].Y;
		if(dx<0){
			back++;
		}else{
			if(dy>0)r++;
			else l++;
		}
	}
	cout << r _ l _ back << endl;
}
