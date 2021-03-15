#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII; // 定义一个堆里单位的数据结构，first是距离，second是节点编号

const int N = 1e6 + 10;

int n, m;
int h[N], w[N], e[N], ne[N], idx;   // 静态链表的定义
// h: 头指针,w: 权重,ne: 下一个指针, idx静态地址
int dist[N];    // 距离矩阵
bool st[N]; // 标记是否被经过过

void add(int a, int b, int c)   // 邻接表的添加节点
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;    // 初始临时变量
    priority_queue <PII, vector<PII>, greater<PII>> heap;   // 顶点堆
    heap.push({0, 1});  // 起点初始化

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        
        // 节点编号，距离
        int ver = t.second, distance = t.first;

        // 查看该节点是否被途径过
        if (st[ver]) continue;
        // 标记，途径
        st[ver] = true;

        // 历遍链表
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];   // ver节点可以连接到的点的编号
            if (dist[j] > dist[ver] + w[i]) // 检测距离矩阵的距离是否可以更新
            {
                dist[j] = dist[ver] + w[i]; // 更新
                heap.push({dist[j], j});    // 往堆里放一会需要计算的点
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;   // 不能到达就返回-1
    return dist[n]; // 返回最后的值
}

int main () {

    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    while (m --)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);   // 添加进表节点
    }
    
    cout << dijkstra() << endl;
    return 0;
}