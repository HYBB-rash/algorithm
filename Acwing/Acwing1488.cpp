// Acwing1488最短距离，做法是超级源点
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int N = 10e6 + 10;

typedef pair<int, int> PII;

int n, m, k, q;

int dist[N];
int e[N], w[N], ne[N], h[N], idx;
bool st[N];

void add (int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void  dijkstra() {

    memset(dist, 0x3f, sizeof dist);

    dist[0] = 0;
    priority_queue <PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 0});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];                
                heap.push({dist[j], j});
            }
        }
    }
}

int main () {

    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    while (m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c); // 无向图
    }
    scanf("%d", &k);
    while (k --) {
        int tmp = 0;
        scanf("%d", &tmp);
        add(0, tmp, 0); // 所有商店都与超级源点建立一个距离0的有向边
    }
    scanf("%d", &q);
    dijkstra();
    while (q --) {
        int start;
        scanf("%d", &start); 
        printf("%d\n", dist[start]);
    }
    return 0;
}