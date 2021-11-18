#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int dist[N], cow[N];
int e[N], w[N], ne[N], h[N], idx;
bool st[N];

int n, p ,c;

void add (int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void spfa(int start) {
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    dist[start] = 0;

    queue<int> q;
    q.push(start);
    st[start] = true;

    while (q.size()) {
        
        auto t = q.front();
        
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

int main () {

    memset(h, -1, sizeof h);
    cin >> n >> p >> c;
    for (int i = 0; i < n; i ++) {
        int ver; cin >> ver;
        cow[ver] ++;
    }
    for (int i = 0; i < c; i ++) {
        int a, b, c; cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    int min_dis = 0x3f3f3f3f;
    for (int i = 1; i <= p; i ++) {
        spfa(i);
        int dis = 0;
        for (int j = 1; j <= p; j ++) {
            if (i != j && cow[j] != 0) {
                dis += cow[j] * dist[j];
            }
        }
        min_dis = min(min_dis, dis);
    }
    cout << min_dis;
    return 0;
}