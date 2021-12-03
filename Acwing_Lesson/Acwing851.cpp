
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N   = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int e[ N ], w[ N ], h[ N ], ne[ N ], idx;
int dist[ N ];
bool st[ N ];

int n, m;

void add( int a, int b, int c ) {
    e[ idx ] = b, w[ idx ] = c, ne[ idx ] = h[ a ], h[ a ] = idx++;
}

int spfa() {

    memset( dist, 0x3f, sizeof dist );
    dist[ 1 ] = 0;

    queue<int> q;
    q.push( 1 );
    st[ 1 ] = true;

    while ( q.size() ) {
        auto t = q.front();
        q.pop();
        st[ t ] = false;
        for ( int i = h[ t ]; i != -1; i = ne[ i ] ) {
            int j = e[ i ];

            // spfa 不备份的原因是: 它不需要完成类似 bell-man ford 的层次搜索
            // 它的主要目的是为了找最短路
            // 由于他用的是队列优化
            // 如果同样去实现 bellman ford 的备份防止串联的效果, 会比较麻烦
            if ( dist[ j ] > dist[ t ] + w[ i ] ) {
                dist[ j ] = dist[ t ] + w[ i ];
                // 改进 bf 算法, 如果上次没有更新这个点, 那么是没有更新的
                // 只需要更新发生了改变的点即可
                if ( !st[ j ] ) q.push( j ), st[ j ] = true;
            }
        }
    }

    if ( dist[ n ] >= ( INF >> 1 ) ) return INF;
    return dist[ n ];
}

int main() {

    memset( h, -1, sizeof h );
    cin >> n >> m;
    for ( int i = 0; i < m; i++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        add( a, b, c );
    }

    int ans = spfa();
    if ( ans == INF )
        cout << "impossible" << endl;
    else
        cout << ans;
    return 0;
}