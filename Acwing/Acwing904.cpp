#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10;

int h[N], e[N], w[N], ne[N], idx;
int dist[N], cnt[N];
bool st[N];

int n, m, chong, f;

void add (int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

bool spfa () {
    queue<int> q;
    for (int i = 1; i <= n; i ++) {
        q.push(i);
        st[i] = true;
        cnt[i] = 0;
    }
    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[t] >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main () {
    cin >> f;
    while (f --) {
        cin >> n >> m >> chong;
        memset(h, -1, sizeof h);
        idx = 0;
        for (int i = 0; i < m; i ++) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c), add(b, a, c);
        }
        for (int i = 0; i < chong; i ++) {
            int a, b ,c;
            cin >> a >> b >> c;
            add(a, b, -c);
        }
        spfa() ? puts("YES") : puts("NO");
    }
    return 0;
}