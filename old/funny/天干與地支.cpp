#include<bits/stdc++.h>
using namespace std;
int main(){
	int y;
	int taiwan_year;
	int ans;
	cin >> y;
	taiwan_year = y-1911;
	ans = taiwan_year;
	int i = 8,j = 0;
	taiwan_year%=60;
	string tan = {"0123456789"};
	string dee = {"0123456789te"};
	taiwan_year--;
	while(taiwan_year--){
		i++;j++;
		if(i>9)i = 0;
		if(j>11)j = 0;
	}
	cout << ans  << dee[i] << tan[j];
}
