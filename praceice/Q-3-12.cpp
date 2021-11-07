#include<bits/stdc++.h>
using namespace std;
int main(){
    int m, n;cin >> m >> n;
    vector<int> v(n);
    map<int,int> MP;
    for(int &x:v){
        cin >> x;
        MP[x] = x;
    }
    int cnter = 0;
    for(auto &x:MP)
        x.second = cnter++;
    for(int &x:v)
        x = MP[x];

    vector<int> cnt(m, 0);
    int num = 0;
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(!cnt[v[i]])
            num++;
        cnt[v[i]]++;
        if(i-m>=0){
            if(cnt[v[i-m]]==1)
                num--;
            cnt[v[i-m]]--;
        }
        if(num == m)
            ans++;
    }
    cout << ans << endl;

}
