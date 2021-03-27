#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int e[N], w[N], h[N], ne[N], idx;
int dist[N];
bool st[N];

int n, m;

void add (int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int spfa() {

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size()){
        auto t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {   // 这里是改进了bf算法的地方。如果上一次这个点没有更新dist，那就算再历遍一次也不会更新。所有这里只把更新了的点放进去队列中等待更新。
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
    
}


int main () {

    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m;i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    int ans = spfa();
    if (ans == -1) cout << "impossible";
    else cout << ans;
    return 0;
    
}