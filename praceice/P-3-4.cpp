#include<bits/stdc++.h>
using namespace std;
#define _ <<" "<<
int main(){
    int n;cin >> n;
    vector<int> v(n+1);
    v[0] = INT_MAX;
    for(int i = 1; i<=n; i++){
        cin >> v[i];
    }
    stack<int> st;
    st.push(0);
    long long ans = 0;
    for(int i = 1; i<=n; i++){
        while(v[st.top()]<=v[i])
            st.pop();
        //cout << i _ st.top() << endl;
        ans+=i-st.top();
        st.push(i);
    }
    cout << ans << endl;
}
