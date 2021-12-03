#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, m, k;

const int N   = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int dist[ N ], backup[ N ];

struct Edge {
    int a, b, w;
} edges[ N ];


// bellman ford 算法可以处理限制边长数的最短路
int bellman_ford() {

    memset( dist, 0x3f, sizeof dist );
    dist[ 1 ] = 0;

    // 如果第 n 次迭代仍然会松弛三角不等式
    // 就说明存在一条长度是 n + 1的最短路径
    // 由抽屉原理，路径中至少存在两个相同的点，说明图中存在负权回路。
    for ( int i = 0; i < k; i++ ) {
        
        // 这里需要备份的原因是会发生串联
        memcpy( backup, dist, sizeof dist );
        for ( int j = 0; j < m; j++ ) {
            int a = edges[ j ].a, b = edges[ j ].b, w = edges[ j ].w;
            if ( dist[ b ] > backup[ a ] + w ) {
                dist[ b ] = backup[ a ] + w;
            }
        }
    }

    // 因为最短路的长度有可能是 -1 , 所以这里需要处理成 INF
    // 不能用 -1 作为出错的标志
    if ( dist[ n ] > INF / 2 ) return INF;
    return dist[ n ];
}

int main() {

    cin >> n >> m >> k;

    for ( int i = 0; i < m; i++ ) {
        cin >> edges[ i ].a >> edges[ i ].b >> edges[ i ].w;
    }
    int ans = bellman_ford();
    if ( ans == INF )
        cout << "impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}