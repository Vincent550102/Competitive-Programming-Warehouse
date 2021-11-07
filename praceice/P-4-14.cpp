#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define Ft first
#define Sd second
#define All(x) x.begin(),x.end()
int main(){
    int n;
    cin >> n;
    vector<pii> v(n);
    for(auto &x:v)
        cin >> x.Ft;
    for(auto &x:v)
        cin >> x.Sd;
    sort(All(v), [](pii a, pii b) -> bool{
       return a.Ft==b.Ft?a.Ft<b.Ft:a.Sd<b.Sd;
    });
    stack<pii> St;
    for(pii x:v){
        while(!St.empty()&&St.top().Ft<=x.Ft&&St.top().Sd<=x.Sd)
            St.pop();
        St.push(x);
    }
    cout << St.size() << endl;

}
