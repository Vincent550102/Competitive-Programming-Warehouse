#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define Ft first
#define Sd second
#define _ <<" "<<
int main(){
    int n; cin >> n;
    vector<pii> v(n);
    int l, r;cin >> l >> r;
    for(auto &x:v)
        cin >> x.Ft >> x.Sd;
    sort(v.begin(), v.end(), [](pii a, pii b){
        return (a.Ft!=b.Ft?a.Ft<b.Ft:a.Sd<b.Sd);
    });
    stack<pii> st;
    bool flag = true;

    for(auto x:v){
        //cout << x.Ft _ x.Sd << endl;
        if(x.Sd<=l || x.Ft>=r) continue;

        if(!st.empty() && st.top().Sd >= x.Sd) continue;
        if(!st.empty() && st.top().Sd < x.Ft){
            //cout << x.Ft << endl;
            flag = false;
            break;
        }
        if(!st.empty() && st.top().Ft <= l && x.Ft<=l) st.pop();
        pii prev = {-1, -1};
        while(!st.empty()&&x.Ft<=st.top().Sd){
            prev = st.top();
            st.pop();
        }
        if(prev.Ft!=-1)
            st.push(prev);
        st.push(x);
    }
    pii prev = {-1, -1};
    while(!st.empty()&&st.top().Sd>=r){
        prev = st.top();
        st.pop();
    }
    if(prev.Ft!=-1)
        st.push(prev);
    //cout << flag << endl;
    cout << (flag ? (int)st.size():-1) << endl;
}
