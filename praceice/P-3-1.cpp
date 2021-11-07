#include<bits/stdc++.h>
using namespace std;
#define mxN 100005
vector<int> G[mxN];
#define _ <<" "<<
int ans = 0;
int dep(int u){
    if(!G[u].size())
        return 0;
    int cnt = 0;
    for(int nxt : G[u]){
        cnt = max(cnt, dep(nxt));
    }
    ans+=cnt+1;
    return cnt+1;
}
int main(){
    int n;
    cin >> n;
    vector<bool> isn_root(n+1,0);
    for(int i = 1; i<=n; i++){
        int k;cin >> k;while(k--){
            int tmp;cin >> tmp;
            G[i].push_back(tmp);
            isn_root[tmp] = 1;
        }
    }
    int root = -1;
    for(int i = 1; i<=n; i++){
        if(!isn_root[i])
            root = i;
    }
    cout << root << endl;
    //int ans = 0;
    dep(root);
    cout << ans << endl;


}
