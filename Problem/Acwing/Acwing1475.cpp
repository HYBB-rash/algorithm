#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

vector<vector<int>> pre(N);

int dist[N];
bool st[N];
int e[N], w[N], ne[N], h[N], idx;

int help[N];
int s,d;

void add (int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});
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
                pre[j].clear();
                pre[j].push_back(ver);
            } else if (dist[j] == dist[ver] + w[i]) {
                pre[j].push_back(ver);
            }
        }
    }
}

vector<int> ans, tmp;
int max_mem = 0, count = 0;

void dfs(int idx, int mem) {

    if (pre[idx].empty()) {
        count ++;
        if (mem > max_mem) {
            max_mem = mem;
            ans = tmp;
        }
        return ;
    }
    for (auto i : pre[idx]) {
        tmp.push_back(i);
        dfs(i, mem + help[i]);
        tmp.pop_back();
    }
}

int main () {

    memset(h, -1, sizeof h);
    int n, m;
    cin >> n >> m >> s >> d;
    for (int i = 0; i < n ; i ++) cin >> help[i];
    for (int i = 0; i < m ; i ++) {
        int a, b, c; cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dijkstra(); dfs(d, help[d]);
    cout << count << " " << max_mem << endl;
    return 0;
}