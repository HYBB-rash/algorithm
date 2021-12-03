#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N   = 510;
const int INF = 0x3f3f3f3f;

int n, m;

int g[ N ][ N ] = { INF };
int dist[ N ]   = { INF };
bool st[ N ]    = { false };

int dijkstra() {

    // 初始化，图论算法一定要初始化距离数组
    memset( dist, 0x3f, sizeof dist );
    // 初始化起点，起点距离为 0
    dist[ 1 ] = 0;

    // 除去起点以外，总共有 n-1 个点，所以总共有 n-1 次循环
    for ( int i = 0; i < n - 1; i++ ) {

        // 寻找最小距离的点
        // 如果没找到，则说明已经没有点可以更新了，直接返回 INF
        int t = -1;
        for ( int j = 1; j <= n; j++ )
            if ( !st[ j ] && ( t == -1 || dist[ t ] > dist[ j ] ) ) t = j;
        if ( t == -1 ) return INF;
        st[ t ] = true;

        // 更新距离
        for ( int j = 1; j <= n; j++ )
            dist[ j ] = min( dist[ j ], dist[ t ] + g[ t ][ j ] );
    }

    return dist[ n ];
}

int main() {

    memset( g, 0x3f, sizeof g );
    cin >> n >> m;

    for ( int i = 0; i < m; i++ ) {
        int a, b, c;
        cin >> a >> b >> c;

        // 处理重边，只需要保留一个最小的边即可
        g[ a ][ b ] = min( g[ a ][ b ], c );
    }

    int res = dijkstra();
    cout << res << endl;

    return 0;
}