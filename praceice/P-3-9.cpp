#include<bits/stdc++.h>
using namespace std;
#define _ <<" "<<
int main(){
    int n,L;
    cin >> n >> L;
    vector<int> v(n), cnt(n,0);
    for(int &x:v)
        cin >> x;
    int now = 0, ans = 0;
    for(int i = 0; i<n; i++){
        if(!cnt[v[i]]){
            now++;
        }
        cnt[v[i]]++;
        if(i-L-1>=0){
            cnt[v[i-L-1]]--;
            if(!cnt[v[i-L-1]]){
                now--;
            }
            //cout << i _ i-L-1 _ now << endl;
        }
        /*for(int x:cnt){
            cout << x << " ";
        }
        cout << endl;*/
        ans = max(ans, now);
    }
    cout << ans << endl;
}
