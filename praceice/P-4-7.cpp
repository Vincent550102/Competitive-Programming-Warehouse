#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = 0; i<n; i++){
        ll tmp;cin >> tmp;
        pq.push(tmp);
    }
    ll ans = 0;
    while(pq.size() > 1){
        ll one = pq.top();
        pq.pop();
        ll two = pq.top();
        pq.pop();
        ans += one+two;
        pq.push(one+two);
    }
    cout << pq.top() <<endl << ans << endl;

}
