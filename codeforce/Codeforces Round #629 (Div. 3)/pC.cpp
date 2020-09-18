#include<bits/stdc++.h>
using namespace std;

string MAX(string a, string b){
	if(a>b)return a;
	else return b;
}

string MIN(string a, string b,string c){
	if(a<b&&a<c)return a;
	else if(b<a&&b<c)return b;
	else return c;
}

string MIN_t(string a, string b){
	if(a<b)return a;
	else return b;
}

char find_min(string a,string b){
	string m1 = MAX(a+'2',b+'0');
	string m2 = MAX(a+'1',b+'1');
	string m3 = MAX(a+'0',b+'2');
	string all_min = MIN(m1,m2,m3);
	if(all_min==m1)return '2';
	else if(all_min==m2)return '1';
	else return '0';
}

int main(){
	int t; cin >> t; while(t--){
		int n;
		cin >> n;
		string ans_a;
		string ans_b;
		string str;
		cin>> str;
		for(int i = 0; i<n; i++){
			if(str[i] == '2'){
				ans_a += find_min(ans_a,ans_b);
				ans_b += '0'+('2'-ans_a[i]);
			}else if(str[i]=='1'){
				string j1 = MAX(ans_a+'1',ans_b+'0');
				string j2 = MAX(ans_a+'0',ans_b+'1');
				string hh = MIN_t(j1,j2);
				if(hh==j1){
					ans_a+='1';
					ans_b+='0';
				}else{
					ans_b+='1';
					ans_a+='0';
				}
			}else{
				ans_b+='0';
				ans_a+='0';
			}
		}
		cout << ans_a << endl << ans_b <<endl;
	}
}
