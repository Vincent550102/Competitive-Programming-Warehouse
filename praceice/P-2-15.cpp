#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> P(n), Q(m), ps(2*n);
    for(int &x:P)
        cin >> x;
    for(int &x:Q)
        cin >> x;

    for(int i = 0; i<2*n; i++){
        ps[i] = (i?ps[i-1]:0)+P[i%n];
    }
    int cur = 0;
    for(int x:Q){
        int tar = (cur?ps[cur-1]:0)+x;
        cur = (lower_bound(ps.begin()+cur, ps.end(), tar)-ps.begin()+1)%n;
        //cout << lower_bound(ps.begin()+cur, ps.end(), tar)-ps.begin() << endl;
    }
    cout << cur << endl;
}
