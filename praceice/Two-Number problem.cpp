#include<bits/stdc++.h>
using namespace std;
#define All(x) x.begin(),x.end()
int main(){
    int m,n,k;
    cin >> m >> n >> k;
    vector<int> v1(m);
    vector<int> v2(n);
    for(int &x:v1)
        cin >> x;
    for(int &x:v2)
        cin >> x;

    sort(All(v1));
    sort(All(v2));
    int ans = 0;
    int rb = n-1;
    for(int lb = 0; lb<m; lb++){
        while(rb >=0 && v1[lb]+v2[rb]>k)
            rb--;
        if(v1[lb]+v2[rb]==k) ans++;
    }
    cout <<ans << endl;

}
