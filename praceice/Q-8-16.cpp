#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e3+5;
map <char, int> MP = {{'@', 0}, {'A', 1}, {'U', 2}, {'C', 3}, {'G', 4}};
int dp[mxN][5];
vector<int> G[mxN];
string str[mxN];
int n, m;

int f(int u, int i){
    if(G[u].empty()){
        if(MP[str[u][i]]==0) return;
        return;
    }
    for(int x:G[u])
        f(x, i);

}

int main(){
    cin >> n >> m;
    int root;
    for(int i = 0; i<n; i++){
        int a,b;
        cin >> a >> b >> str[i];
        if(a==b) root = a;
        else{
            G[b].push_back(a);
        }
    }
    int ans = 0;
    for(int i = 0; i<m; i++){
        f(root, i);
        ans += dp[root][0];
    }
}
