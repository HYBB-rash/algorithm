#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;

int g[N][N];    // 图数据
int dist[N];    // 距离矩阵
bool st[N];     // 标记点是否被经过过

int dijkstra(int n, int idxS, int idxE)
{
    memset(dist, 0x3f, sizeof dist);    // 初始化距离矩阵
    dist[idxS] = 0; // 起点到起点的距离是0

    for (int i = 0; i < n - 1; i ++) 
    {
        int t = -1; // 初始临时变量
        for (int j = 1; j <= n; j ++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;  // 如果该点没有被记录过，且距离矩阵记录的是最小距离，就更新t临时变量

        for (int j = 1; j <= n; j ++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);  // 更新距离矩阵
        
        st[t] = true;   // 表示该点已经被途径过
    }

    if (dist[idxE] == 0x3f3f3f3f) return -1;    // 如果该点未被途径，则返回-1
    return dist[idxE];  // 否则返回实际的距离
}

int main() 
{
    memset(g, 0x3f, sizeof g);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i ++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        g[x][y] = min(g[x][y], d);  // 这是有向图，且有重边的写法。有重边且需要最小时取min即可
    }
    int ans = dijkstra(n, 1, n);
    cout << ans;
    return 0;
}

