	#include<bits/stdc++.h>
	using namespace std;
	int main(){
		int t;cin >> t;while(t--){
			long long int num,ans=0,point=1;
			cin>>num;
			if(num==1){
				cout<<1<<endl;
				continue;
			}
			for(int i=9;i>1;i--){
				while(num%i==0){
					num/=i;
					ans+=i*point;
					point*=10;
				}
			}
			if(num==1)cout<<ans<<endl;
			else cout<<-1<<endl;
		}
	}
