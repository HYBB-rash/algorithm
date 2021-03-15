#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e6 + 10;

typedef pair<int, int> PII;

int n, m;

int dist[N];
int e[N], w[N], ne[N], h[N], idx;
bool st[N];

void add (int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void dijkstra() {

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue <PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while(heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j})
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    ans = dijkstra();
    double rate = (100 + ans) / 100;
    printf("%.8f", 100 * rate);
    return 0;
}