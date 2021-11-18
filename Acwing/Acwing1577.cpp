// Acwing 1577 条条大路通罗马
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

const int N = 1e3 + 10;

typedef pair<int, int> PII;

// 保存最短路径可以到这个点的上一个点的编号。用dfs回溯
vector<vector<int>> pre(N); // pre数组，用来回溯路径，记录最短的路径的上一个点是什么

int dist[N];
bool st[N];
int e[N], w[N], h[N], ne[N], idx;

unordered_map<int, int> happy;
unordered_map<string, int> city_idx;
string citys[N];
int c_idx = 0;

void add (int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void dijkstra() {

    int start_idx = city_idx["ROM"];
    memset(dist, 0x3f, sizeof dist);
    dist[start_idx] = 0;
    priority_queue <PII, vector<PII>, greater<PII>> heap;
    heap.push({0, start_idx});
    
    while (heap.size()) {
        auto t = heap.top();
        int ver = t.second, distance = t.first;
        heap.pop();

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
                pre[j].clear(); // 如果发现了有更短的路径，则需要清除之前的pre数组路径，之前的点数据都失效
                pre[j].push_back(ver);  // 将新的点放入pre数组
            } else if (dist[j] == dist[ver] + w[i]) {
                pre[j].push_back(ver);  // 将可以到达这个点的最短路径放进pre数组
            }
        }
    }
}

vector<int> ans, tmp;   // ans数组是保存最终答案，tmp数组是dfs的临时数组
int max_happy = 0, min_steps = N, way_count = 0;    // 根据题目需求制定的变量

void dfs(int idx, int weight, int steps) {
    if (pre[idx].empty()) { // 递归出口
        way_count ++;   // pre数组空了，说明到起点了，已经历遍了一整条路
        if (max_happy < weight) {   // 按照题目要求编写
            max_happy = weight;
            min_steps = steps;
            ans = tmp;
        } else if (max_happy == weight) {
            if (min_steps > steps) {
                min_steps = steps;
                ans = tmp;
            }
        }
        return ;
    }
    for (auto i : pre[idx]) {
        tmp.push_back(i);   // 路径记录
        dfs(i, weight + happy[i], steps + 1);
        tmp.pop_back(); // 回溯
    }
}

int main () {
    memset(h, -1, sizeof h);
    int n, m; string dest;
    cin >> n >> m >> dest;
    city_idx[dest] = c_idx ++;
    for (int i = 0; i < n - 1; i ++) {
        string city; int weight;
        cin >> city >> weight;
        citys[c_idx] = city;
        city_idx[city] = c_idx ++;
        happy[city_idx[city]] = weight;
    }

    for (int i = 0; i < m; i ++) {
        string start, end; int weight = 0;
        cin >> start >> end >> weight;
        int start_idx = city_idx[start], end_idx = city_idx[end];
        add(start_idx, end_idx, weight);
        add(end_idx, start_idx, weight);
    }

    dijkstra();
    dfs(city_idx[dest], 0, 0);
    cout << way_count << " " << dist[city_idx[dest]] << " " << max_happy << " " << max_happy / min_steps << endl;
    cout << dest;
    for (auto i : ans) cout << "->" << citys[i];
    return 0;
}