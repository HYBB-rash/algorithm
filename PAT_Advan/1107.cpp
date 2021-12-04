// 并查集的应用
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

const int N = 100010;

int p[ N ], s[ N ];

int find( int x ) {
    if ( p[ x ] != x ) p[ x ] = find( p[ x ] );
    return p[ x ];
}

void uni( int a, int b ) {
    s[ find( b ) ] += s[ find( a ) ];
    p[ find( a ) ] = find( b );
}

int main() {
    int n;
    cin >> n;
    for ( int i = 0; i <= n; i++ )
        s[ i ] = 1;
    for ( int i = 0; i < N; i++ )
        p[ i ] = i;

    for ( int i = 0; i < n; i++ ) {
        int k;
        scanf( "%d: ", &k );
        while ( k-- ) {
            int hab;
            cin >> hab;
            uni( i + 1, hab + n );
        }
    }

    set<pair<int, int>> list;
    for ( int i = 1; i <= n; i++ ) {
        list.insert( { s[ find( i ) ], find( i ) } );
    }

    vector<int> ans;
    for ( auto &kv : list ) {
        ans.push_back( kv.first );
    }
    cout << ans.size() << endl;
    for ( int i = ans.size() - 1; i >= 0; i-- ) {
        if ( i != ans.size() - 1 ) cout << " ";
        cout << ans[ i ];
    }
    return 0;
}
