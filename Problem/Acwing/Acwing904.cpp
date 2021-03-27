#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
// TODO求负环
const int N = 1e5 + 10;

int dist[N];
bool st[N];
int e[N], t[N], ne[N], h[N], idx;

int add (int a, int b, int c) {
    e[idx] = b, t[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void spfa () {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size()) {
        int ver = q.front();
        q.pop();
        st[ver] = false;

        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + t[i]) {
                dist[j] = dist[ver] + t[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

int main () {

    int f = 0; cin >> f;
    while (f --) {
        memset(h, -1, sizeof h);
        idx = 0;
        int n, m, w;
        cin >> n >> m >> w;
        for (int i = 0; i < m; i ++) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c), add(b, a, c);
        }
        for (int i = 0; i < w; i ++) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, -c);
        }
        spfa();

    }
}