#include<bits/stdc++.h>
using namespace std;
vector<bool > map_sieve(100005,true);
void Sieve_Eratosthenes(){
	map_sieve[0] = false; 
	map_sieve[1] = false;
	int sqrt_num = sqrt(100005);
	for(int i = 2; i<sqrt_num; i++){
		if(map_sieve[i]){
			for(int j = i*i; j<100005; j++){
				map_sieve[j] = false;
			}
		}
	}
}

int main(){
	while(true){
		int n;
		cin >>n;
		
	}
	
	
	
	
	
}
