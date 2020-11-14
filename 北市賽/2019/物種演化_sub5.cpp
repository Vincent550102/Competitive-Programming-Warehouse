#pragma GCC optimize("O3,unroll-loops")
#pragma loop_opt(on)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
#define endl '\n'
constexpr int mxN = 1e5+5;
vector<int> G[mxN];
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,m;
int f[mxN][25],dep[mxN];

#define _ <<" "<<
void dfs(int u,int v,int d){
    dep[v]=d;
    f[v][0]=u;
    for(int x:G[v]){
        if(x!=u)dfs(v,x,d+1);
    }
}

void build(){
    for(int up = 1; (1<<up)<n; up++){
        for(int i = 0; i<n; i++){
            f[i][up]=f[f[i][up-1]][up-1];
        }
    }
}

int Lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    int most_dep = 1;
    while((1<<(most_dep+1))<=dep[u])most_dep++;
    for(int i = most_dep;i>=0;i--){
        if(dep[f[u][i]]>=dep[v]){
            u=f[u][i];
        }
    }
    if(u==v)return u;
    for(int i = most_dep; i>=0; i--){
        if(f[u][i]!=f[v][i]){
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}

template <typename T>
inline void hash_combine(std::size_t &seed, const T &val) {
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
// auxiliary generic functions to create a hash value using a seed
template <typename T> inline void hash_val(std::size_t &seed, const T &val) {
    hash_combine(seed, val);
}
template <typename T, typename... Types>
inline void hash_val(std::size_t &seed, const T &val, const Types &... args) {
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline std::size_t hash_val(const Types &... args) {
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        return hash_val(p.first, p.second);
    }
};
signed main(){
    io_op
    cin >> n >> m;
    for(int i = 0; i<n-1; i++){
        int a,b;cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    dfs(0,0,0);
    f[0][0]=0;
    build();
    unordered_map<pair<int,int>,int,pair_hash> MP;
    while(m--){
        int a,b;
        cin >> a >> b;
        if(MP.count({a,b}))cout << MP[{a,b}];
        else{
            int ans = dep[a]+dep[b]-2*dep[Lca(a,b)];
            MP[{a,b}]=ans;
            cout << ans;
        }
        cout << endl;
    }
} 
