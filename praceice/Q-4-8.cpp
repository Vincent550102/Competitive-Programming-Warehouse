#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i<m; i++){
        pq.push(0);
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        int tmp;cin >>tmp;
        int now = pq.top()+tmp;
        ans = max(ans, now);
        pq.pop();
        pq.push(now);
    }
    cout << ans << endl;
}
