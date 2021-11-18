// Acwing1375 奶牛回家
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int g[N][N];
int st[N];
int dist[N];
int e = 55, min_d = 0x3f3f3f3f;

// 牧场的数量是恒定的52个，用大写和小写表示
//这里用两个个转化函数让char变成int,int变成char
int getIndex(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a' + 1;
    return c - 'A' + 27;
}

char getOrigin(int ver) {
    if (ver > 26) return (char) ver - 27 + 'A';
    return (char) ver - 1 + 'a';
}

int dijkstra() {

    memset(dist, 0x3f, sizeof dist);
    dist[getIndex('Z')] = 0;
    for (int i = 0; i < getIndex('Z'); i ++) {
        int t = -1;
        for (int j = 1; j <= getIndex('Z'); j ++) {
            if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
        }
        for (int j = 1; j <= getIndex('Z'); j ++) {
            if (dist[j] > dist[t] + g[t][j]) {
                dist[j] = dist[t] + g[t][j], dist[j];
                // 记录最小距离的点，要求是大写的char以及不是从牛棚里出来的
                if (j != getIndex('Z') && j >= 27 && dist[j] < min_d) {
                    min_d = dist[j], e = j; // 记录一下最小距离的点
                }
            }
        }
        st[t] = true;
    }
    if (dist[e] == 0x3f3f3f3f) return -1;
    return dist[e];
}

int main () {
    int n = 0;
    cin >> n;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < n; i ++) {
        char s, e; int d;
        cin >> s >> e >> d;
        g[getIndex(s)][getIndex(e)] = min(g[getIndex(s)][getIndex(e)], d);
        g[getIndex(e)][getIndex(s)] = min(g[getIndex(e)][getIndex(s)], d);
    }
    dijkstra();
    cout << getOrigin(e) << " " << min_d ;
    return 0;
}