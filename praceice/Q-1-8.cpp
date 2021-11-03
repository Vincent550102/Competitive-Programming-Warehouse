#include<bits/stdc++.h>
#define mxN 30
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
ll arr[mxN], P;
int n;
ll ans = -1;
void sol(int i = 0, ll now = 0){
    if(i>=n){
        if(now < P) ans = max(ans, now);
        return;
    }
    sol(i+1, now+arr[i]);
    sol(i+1, now);
}

int main(){
    io_op
    cin >> n >> P;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    sol();
    cout << ans << endl;

}
