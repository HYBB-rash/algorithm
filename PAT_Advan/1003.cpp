// 最短路 + DFS
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N   = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int e[ N ], w[ N ], ne[ N ], h[ N ], idx = 0;

void add( int a, int b, int c ) {
    e[ idx ] = b, w[ idx ] = c, ne[ idx ] = h[ a ], h[ a ] = idx++;
}

vector<vector<int>> path;
int dist[ N ];
bool st[ N ];
int teams[ N ];

int n, m, ori, tar;

int spfa( int ori ) {
    memset( dist, 0x3f, sizeof dist );
    dist[ ori ] = 0;
    queue<int> q;
    q.push( ori ), st[ ori ] = true;

    while ( q.size() ) {
        auto t = q.front();
        q.pop(), st[ t ] = false;

        for ( int i = h[ t ]; i != -1; i = ne[ i ] ) {
            int j = e[ i ];
            if ( dist[ j ] > dist[ t ] + w[ i ] ) {
                dist[ j ] = dist[ t ] + w[ i ];
                path[ j ].clear();
                path[ j ].push_back( t );
                if ( !st[ j ] ) q.push( j ), st[ j ] = true;
            } else if ( dist[ j ] == dist[ t ] + w[ i ] ) {
                path[ j ].push_back( t );
            }
        }
    }

    if ( dist[ tar ] > ( INF >> 1 ) ) return INF;
    return dist[ tar ];
}

int max_team = 0;
int dfs( int n, int cost ) {

    int path_nums = 0;
    for ( auto &node : path[ n ] ) {
        path_nums += dfs( node, cost + teams[ n ] );
    }
    max_team = max( max_team, cost + teams[ n ] );
    return path_nums == 0 ? 1 : path_nums;
}

int main() {

    cin >> n >> m >> ori >> tar;

    path.resize( n + 1 );

    memset( h, -1, sizeof h );
    for ( int i = 0; i < n; i++ )
        cin >> teams[ i ];
    for ( int i = 0; i < m; i++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        add( a, b, c );
        add( b, a, c );
    }

    int min_dist = spfa( ori );
    int max_path = dfs( tar, 0 );

    cout << max_path << " " << max_team ;


    return 0;
}