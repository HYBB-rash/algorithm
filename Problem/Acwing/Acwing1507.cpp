// Acwing1507 旅行计划

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> PII;

map<PII, int> cost_map;

const int N = 1e5 + 10;

int dist[N];
bool st[N];
int e[N], w[N], ne[N], h[N], idx;

int s, d;

vector<vector<int>> pre(N);

void add (int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h [a] = idx ++; 
}

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    priority_queue <PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});
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
                heap.push({dist[j], j});
                pre[j].clear();
                pre[j].push_back(ver);
            } else if (dist[j] == dist[ver] + w[i]) {
                pre[j].push_back(ver);
            }
        }
    }
}

vector<int> ans, tmp;
int min_cost = 0x3f3f3f3f;

void dfs(int idx, int cost) {
    if (pre[idx].empty()) {
        if (min_cost > cost) {
            min_cost = cost;
            ans = tmp;
        }
        return;
    }
    for (auto i : pre[idx]) {
        tmp.push_back(i);
        dfs(i, cost + cost_map[{idx, i}]);
        tmp.pop_back();
    }
}

int main () {

    memset(h, -1, sizeof h);
    int n, m;
    cin >> n >> m >> s >> d;
    for (int i = 0; i < m; i ++) {
        int start, end, weight, cost;
        cin >> start >> end >> weight >> cost;
        add(start, end, weight), add(end, start, weight);
        cost_map[{start, end}] = cost, cost_map[{end, start}] = cost;
    }
    dijkstra();
    dfs(d, 0); 
    for (int i = ans.size() - 1; i >= 0; i --) cout << ans[i] << " ";
    cout << d << " ";
    cout << dist[d] << " " << min_cost;
    return 0;
}