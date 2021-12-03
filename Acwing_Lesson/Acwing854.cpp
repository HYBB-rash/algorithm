#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N   = 510;
const int INF = 0x3f3f3f3f;

int g[ N ][ N ];
bool st[ N ];

int n, m, k;

// 基于动态规划的最短路径
void floyd() {

    for ( int k = 1; k <= n; k++ )
        for ( int i = 1; i <= n; i++ )
            for ( int j = 1; j <= n; j++ )
                g[ i ][ j ] = min( g[ i ][ j ], g[ i ][ k ] + g[ k ][ j ] );
}

int main() {
    // 初始化图的矩阵
    memset( g, 0x3f, sizeof g );
    // 这里要把对角线的值设定成 0 自己到自己距离一定是 0
    for ( int i = 0; i < N; i++ )
        g[ i ][ i ] = 0;
    cin >> n >> m >> k;

    for ( int i = 0; i < m; i++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        // 处理重边
        g[ a ][ b ] = min( g[ a ][ b ], c );
    }

    floyd();

    for ( int i = 0; i < k; i++ ) {
        int a, b;
        cin >> a >> b;
        if ( g[ a ][ b ] >= ( INF >> 1 ) )
            cout << "impossible" << endl;
        else
            cout << g[ a ][ b ] << endl;
    }
    return 0;
}