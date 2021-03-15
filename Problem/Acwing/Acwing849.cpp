#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int dist[N];
int g[N][N];
int st[N];

int dijkstra(int n, int start, int end) {

    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;

    for (int i = 0; i < n - 1; i ++) {

        int t = -1;
        for (int j = 1; j <= n; j ++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        
        for (int j = 1; j <= n; j ++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }

    if (dist[end] == 0x3f3f3f3f) return -1;
    return dist[end];
}

int main () {

    int n = 0, m = 0;
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int s, e, d;
        cin >> s >> e >> d;
        g[s][e] = min(g[s][e], d);
    }
    int ans = dijkstra(n, 1, n);
    cout << ans;
    return 0;
}