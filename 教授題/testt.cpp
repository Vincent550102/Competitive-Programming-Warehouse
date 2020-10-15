#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[5] = {1,2,4,5,6};
	int lb = 0,rb = 5-1,mb;
	int f= 3;
	while(rb>=lb){
		mb = lb+rb>>1;
		if(arr[mb]>f)rb=mb-1;
		else if(arr[mb]<f)lb=mb+1;
		else break;
	}
	cout << arr[mb] << endl;
}
