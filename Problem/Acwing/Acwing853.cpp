#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, k;

const int N = 1e5 + 10;

int dist[N],backup[N];

struct Edge
{
    int a, b, w;
}edges[N];


int bellman_ford() {

    memset(dist, 0x3f, sizeof dist);    // 初始化dist数组
    dist[1] = 0;    // dist数组起点设定为0

    for (int i = 0; i < k; i ++) {  // 如果没有限制边数，这里就是点的个数，否则循环k次
        memcpy(backup, dist, sizeof dist);  // 这里要复制一下数组，否则直接用dist数组更行会出现串更的情况
        for (int j = 0; j < m; j ++) {  // 对每条边都循环一次
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if (dist[b] > backup[a] + w) {  // 松弛操作
                dist[b] = backup[a] + w;
            }
        }
    }

    if (dist[n] > 0x3f3f3f3f /2) return -1;
    return dist[n];
}

int main() {

    cin >> n >> m >> k;

    for (int i = 0; i < m; i ++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }
    int ans = bellman_ford();
    if (ans == -1) cout << "impossible" << endl;
    else cout << ans << endl;
    return 0;

}