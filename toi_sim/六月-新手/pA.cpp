#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int total = 0;
	while(cin >> n&&n){
		if(n==1){
			int tmp;
			cin >> tmp;
			if(tmp==1){
				cout << "Medium Wac 4";
				total+=4;
			}else if(tmp==2){
				cout << "WChicken Nugget 8";
				total+=8;
			}else if(tmp==3){
				cout << "Geez Burger 7 ";
				total+=7;
			}else if(tmp==4){
				cout << "ButtMilk Crispy Chicken 6";
				total+=6;
			}else if(tmp==5){
				cout << "Plastic Toy 3";
				total+=3;
			}
		}else{
			int tmp;
			cin>> tmp;
			if(tmp==1){
				cout << "German Fries 2";
				total+=2;
			}else if(tmp==2){
				cout << "Durian Slices 3";
				total+=3;
			}else if(tmp==3){
				cout << "WcFurry 5";
				total+=5;
			}else if(tmp==4){
				cout << "Chocolate Sunday 7";
				total+=7;
			}
		}
		cout << endl;
	}
	cout << "Total: " << total << endl;
}
