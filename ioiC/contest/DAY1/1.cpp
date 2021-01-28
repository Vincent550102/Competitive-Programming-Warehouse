#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, dis[505][505];

void dp() {
    // floyd-warshall algorithm
    for (int i = 1; i <= n; ++i)
        for (int k = 1; k <= n; ++k)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main() {
    int m, h, p, a, b, d;
    // input N M
    scanf("%d%d", &n, &m);
    h = 1, p = n;
    // initialize each weight of edges to INF
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dis[i][j] = INF;
    // i -> i is zero
    for (int i = 1; i <= n; ++i)
        dis[i][i] = 0;
    // input edges
    while (m--) {
        scanf("%d%d%d", &a, &b, &d);
        // don't forget the multiple edges!
        dis[a][b] = min(dis[a][b], d);
    }
    // run floyd-warshall
    dp();
    // input h and p, actually they remain the same
    scanf("%d%d", &h, &p);
    // print the distance from h to p
    printf("%d\n", dis[h][p]);
    while (scanf("%d%d", &a, &b) != EOF) {
        // output the answer for each query
        if (dis[h][a] == INF || dis[a][b] == INF || dis[b][p] == INF)
            printf("-1\n");
        else
            printf("%d\n", dis[h][a] + dis[a][b] + dis[b][p]);
    }
}
