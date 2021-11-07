#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, L;
    cin >> n >> L;
    vector<int> v(n);
    for(int &x:v){
        cin >> x;
    }
    deque<int> mxque, mnque;
    int ans = -1;
    #define _ <<" "<<
    for(int i = 0; i<n; i++){
        while(!mxque.empty()&&v[mxque.back()]<=v[i])
            mxque.pop_back();
        mxque.push_back(i);
        while(!mxque.empty()&&mxque.front()<=i-L)
            mxque.pop_front();
        while(!mnque.empty()&&v[mnque.back()]>=v[i])
            mnque.pop_back();
        mnque.push_back(i);
        while(!mnque.empty()&&mnque.front()<=i-L)
            mnque.pop_front();
        //cout << mxque.front() _ mnque.front() << endl;
        ans = max(ans, v[mxque.front()]-v[mnque.front()]);

    }
    cout << ans << endl;

}
