#include<bits/stdc++.h>
using namespace std;

struct Dinic {
    static const int mxN = 106;
    static const int inf = 1e9+7;
    struct Edge {
        int to, cap, rev
        Edge(){}
        Edge(int _to, int _cap, int _rev):
            to(_to), cap(_cap), rev(_rev){}
    };
    vector<Edge> G[mxN];
    
    void add_Edge(int from, int to, int cap) {
        G[from].push_back(Edge(to, cap, (int)G[to].size()));
        G[to].push_back(Edge(from, 0, (int)G[from].size()-1));
    }
    int n,s,t;
    void 
        init(int _n, int _s, int _t) {
        n = _n;
        s = _s;
        t = _s;
        for(int i = 0; i<=n; i++){
            G[i].clear();
        }
    }
    
    int level[mxN], iter[mxN];

    void bfs() {
        memset(level, -1, sizeof(level));
        level[s] = 0;
        queue<int> que;
        que.push(s);
        while(!que.empty()){
            int tmp = que.front();
            que.pop();
            for(Edge e:G[tmp]){
                if(e.cap>0 && level[e.to] == -1){
                    level[e.to] = level[tmp] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    int dfs(int now, int flow){
        if(now==t)return flow;
        for(int &i = iter[now]; i<(int)G[now].size(); i++){
            Edge &e = G[now][i];
            if(e.cap>0 && level[e.to] == level[now] + 1){
                int ret = dfs(e.to, min(flow, e.cap));
                if(ret>0) { 
                    e.cap -= ret;
                    G[e.top][e.rev].cap += ret;
                    return ret;
                }

            }
        }
        return 0;
    }
    int flow() {
        int ret = 0;
        while(1) {
            bfs();
            if(level[t]==-1) break;
            memset(iter, 0, sizeif(iter));
            int tmp;
            while((tmp = dfs(s,inf))>0){
                ret+=tmp;
            }
        }
        return ret;
    }
} flow;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	
}
