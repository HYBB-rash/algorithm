#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e6 + 10;
const double money_max = 5e100 + 10;    // 这里的距离是从起点开始转账到这个这个人需要的钱

typedef pair<double, int> PII;

int n, m;
double dist[N];
int e[N], w[N], ne[N], h[N], idx;
bool st[N];

void add (int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
// 这里采用堆优化dijkstra
double dijkstra(int start, int end) {

    for (int i = 0; i < N - 1; i ++) {
        dist[i] = money_max;
    }
    dist[start] = 100.0;    // 题意，初始100块钱
    priority_queue <PII, vector<PII>, greater<PII>> heap;
    heap.push({100.0, start});

    while(heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second;
        double distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] / (1.0 - w[i] * 1.0 / 100.0)) {
                dist[j] = dist[ver] / (1.0 - w[i] * 1.0 / 100.0);   // 扣除费率后转账所需要的钱
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[end] == money_max) return -1;
    return dist[end];
}

int main () {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);   // 这里的是每个人都能互相转账，因此是无向图
    }
    int start, end;
    cin >> start >> end;
    double ans = dijkstra(start, end);
    printf("%.8lf", ans);
    return 0;
}