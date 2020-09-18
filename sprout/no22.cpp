#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
class pp{
	private:
		int __val;
		long long __size;
	public:
		pp(int a,int b){__val=a;__size=b;}
		int operator++(int a){if(a==0)return __size++;}
		bool operator<=(int a){return __val<=a;}
		bool operator==(int a){return __val==a;}
		friend void operator+=(long long &a, pp b){a+=b.__size;}
};
#define int ll
stack<pp> ss;

signed main(){
	FAST
	int t;cin >> t;while(t--){
		int sz;
		int ans=0;
		cin >> sz;
		while(!ss.empty())ss.pop();
		for(int i=0;i<sz;i++){
			int aaa;
			cin >> aaa;
			int kk=1;
			while(!ss.empty()&&(ss.top()<=aaa)){
				if(ss.top()==aaa) kk+=ss.top();
				ans+=ss.top();
				ss.pop();
			}
			if(!ss.empty())ans++;
			ss.push(pp(aaa,kk));
		}
		cout << ans << endl;
	}
	return 0;
}
