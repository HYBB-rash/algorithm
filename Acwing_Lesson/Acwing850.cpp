
#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 用来表示距离和点, first 是距离, second 是点的编号
typedef pair<int, int> PII;

const int N   = 1e6 + 10;
const int INF = 0x3f3f3f3f;

// 邻接表的定义，这里使用静态链表处理
int h[ N ], e[ N ], ne[ N ], w[ N ], idx = 0;
int n, m;

int dist[ N ] = { INF };
bool st[ N ]  = { false };

// 邻接表的加边操作
void add( int a, int b, int c ) {
    e[ idx ] = b, w[ idx ] = c, ne[ idx ] = h[ a ], h[ a ] = idx++;
}

// dijkstra 算法的堆优化版本
// 适合稀疏图
int dijkstra() {

    memset( dist, 0x3f, sizeof dist );
    dist[ 1 ] = 0;

    // 使用小顶堆处理距离, 让距离最小的点在顶
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    // 初始的距离是 0 
    heap.push( { 0, 1 } );

    while ( heap.size() ) {

        // 堆优化主要就是优化这里
        // 不再需要遍历找最小的点,只需拿堆顶的元素即可
        PII point = heap.top();
        heap.pop();

        int ver = point.second, dis = point.first;

        // 如果堆顶元素之前用过, 那么不要再做这个循环
        if ( st[ ver ] ) continue;
        st[ ver ] = true;

        // 更新点的距离
        for ( int i = h[ ver ]; i != -1; i = ne[ i ] ) {
            int j = e[ i ];
            if ( dist[ j ] > dist[ ver ] + w[ i ] ) {
                dist[ j ] = dist[ ver ] + w[ i ];
                // 把更新过的点放进堆里
                heap.push( { dist[ j ], j } );
            }
        }
    }

    if ( dist[ n ] == INF ) return -1;
    return dist[ n ];
}

int main() {
    scanf( "%d%d", &n, &m );
    memset( h, -1, sizeof h );

    while ( m-- ) {
        int a, b, c;
        scanf( "%d%d%d", &a, &b, &c );
        add( a, b, c );
    }

    cout << dijkstra() << endl;
    return 0;
}