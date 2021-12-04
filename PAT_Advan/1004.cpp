#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N   = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int e[ N ], ne[ N ], h[ N ], idx = 0;

void add( int a, int b ) { e[ idx ] = b, ne[ idx ] = h[ a ], h[ a ] = idx++; }

int n, m;

// 标准的层序遍历 有分层遍历的需求

int main() {

    memset( h, -1, sizeof h );
    cin >> n >> m;
    for ( int i = 0; i < m; i++ ) {
        int node, k;
        cin >> node >> k;
        for ( int j = 0; j < k; j++ ) {
            int c;
            cin >> c;
            add( node, c );
        }
    }

    int root = 1;
    queue<int> cur, tmp;
    cur.push( root );
    vector<int> ans;
    while ( cur.size() ) {
        int cnt = 0;
        while ( !cur.empty() ) {
            int node = cur.front();
            cur.pop();

            if ( h[ node ] == -1 ) cnt++;

            for ( int t = h[ node ]; t != -1; t = ne[ t ] )
                tmp.push( e[ t ] );
        }
        ans.push_back( cnt );
        while ( !tmp.empty() )
            cur.push( tmp.front() ), tmp.pop();
    }

    int out_cnt = 0;
    for ( int &a : ans ) {
        if ( out_cnt != 0 ) cout << " ";
        cout << a;
        out_cnt++;
    }


    return 0;
}