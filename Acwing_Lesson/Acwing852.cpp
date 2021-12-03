#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N   = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int h[ N ], e[ N ], w[ N ], ne[ N ], idx = 0;
int dist[ N ], cnt[ N ];
bool st[ N ];

int n, m;

void add( int a, int b, int c ) {
    e[ idx ] = b, w[ idx ] = c, ne[ idx ] = h[ a ], h[ a ] = idx++;
}

// 使用 spfa 判断有没有负环是最高效的方法
// 如果图里面有负环, 那么这个负环的路径一定是 负无穷
bool spfa() {

    // 使用 spfa 判断图里面有没有负环不需要初始化 dist 数组
    queue<int> q;

    // 这里把所有的点都加了进去
    // 因为是判断图里面有没有负环, 而不是问从点 1 开始的最短路径有没有负环
    // 所以这里需要把所有的点加进去
    for ( int i = 1; i <= n; i++ ) {
        q.push( i );
        st[i] = true;
    }

    while ( q.size() ) {
        auto t = q.front();
        q.pop();
        st[ t ] = false;

        for ( int i = h[ t ]; i != -1; i = ne[ i ] ) {
            int j = e[ i ];

            if ( dist[ j ] > dist[ t ] + w[ i ] ) {
                dist[ j ] = dist[ t ] + w[ i ];
                cnt[ j ]  = cnt[ t ] + 1;
                if ( cnt[ j ] >= n ) return true;
                if ( !st[ j ] ) q.push( j ), st[ j ] = true;
            }
        }
    }
    return false;
}

int main() {

    memset( h, -1, sizeof h );
    cin >> n >> m;
    for ( int i = 0; i < m; i++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        add( a, b, c );
    }

    string ans;
    spfa() ? ans = "Yes" : ans = "No";
    cout << ans;
    return 0;
}