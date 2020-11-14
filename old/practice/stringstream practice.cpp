#include<bits/stdc++.h> 

#define ss stringstream

using namespace std;
int main(){
	string str;
	while(getline(cin,str)){
		string tmp;
		ss box(str);
		int sum = 0;
		while(box >> tmp){
			bool is_all_Num = true;
			int len = tmp.size();
			for(int i = 0; i<len; i++){
				if(tmp[i] <'0' || tmp[i] >'9') is_all_Num = false;
			}
			if(is_all_Num){
				ss transform;
				int Num;
				transform << tmp;
				transform >> Num;
				sum += Num;
			}
		}
		cout << sum << '\n';
	}
		
	
}
