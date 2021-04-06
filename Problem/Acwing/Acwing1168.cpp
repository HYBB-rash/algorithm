#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;

int dist[N], cnt[N];
bool st[N];
int e[N], w[N], ne[N], h[N], idx;

int n, m, s;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

bool spfa_minus() {
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    for (int i = 1; i <= n; i ++) {
        q.push(i);
        st[i] = true;
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

bool spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    memset(st, 0, sizeof st);
    queue<int> q;
    q.push(s);
    st[s] = true;

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
    return false;
}

int main () {

    memset(h, -1, sizeof h);
    cin >> n >> m >> s;
    for (int i = 0; i < m; i ++) {
        int  a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    if (spfa_minus()) {
        cout << -1;
    } else {
        spfa();
        for (int i = 1; i <= n; i ++) {
            if (dist[i] >= 0x3f3f3f3f / 2) cout << "NoPath" << endl;
            else cout << dist[i] << endl;
        }
    }
    return 0;
}