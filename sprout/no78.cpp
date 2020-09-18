#include<bits/stdc++.h>
using namespace std;
int main(){
	int gift[7];
	while(1){
		for(int i = 1; i<7; i++)cin >> gift[i];
		bool flag = true;
		for(int i = 1; i<7; i++)if(gift[i]!=0)flag = false;
		if(flag)break;
		int ans = gift[6]+gift[5]+gift[4];
		gift[1] -= 11*gift[5];
		gift[2]-= 5*gift[4];
		ans += (gift[3]/4); 
		if(gift[3]%4) ans++;
		if(gift[3]%4==1){
			gift[2]-=5;
			gift[1]-=7;
		}else if(gift[3]%4==2){
			gift[2]-=3;
			gift[1]-=6;
		}else if(gift[3]%4==3){
			gift[2]-=1;
			gift[1]-=5;
		}
		if (gift[2]>0){   
            ans+=gift[2]/9; if(gift[2]%9) ans++;
            gift[1]-=(36-(gift[2]%9)*4);
        }else if (gift[2]<0)
            gift[1]-= (-gift[2])*4; 
		if (gift[1]>0){   
             ans+=(gift[1]/36); if(gift[1]%36) ans++;
        }
        cout << ans << endl;
	}
}
