// 树的遍历 DFS 的应用
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

const int N = 1e6 + 10;

int e[ N ], ne[ N ], h[ N ], idx = 0;
map<int, int> prods;
void add( int a, int b ) { e[ idx ] = b, ne[ idx ] = h[ a ], h[ a ] = idx++; }

int n;
double rate, price;

double sum = 0;

void dfs( int idx, double cost ) {

    if ( h[ idx ] == -1 ) {
        sum += cost * prods[ idx ];
        return;
    }
    cout << cost << endl;
    for ( int t = h[ idx ]; t != -1; t = ne[ t ] ) {
        int j = e[ t ];
        dfs( j, cost * ( 1.0 + 0.01 * rate ) );
    }
}

int main() {
    cin >> n >> price >> rate;

    memset( h, -1, sizeof h );

    for ( int i = 0; i < n; i++ ) {
        int k;
        cin >> k;
        if ( k == 0 ) {
            cin >> prods[ i ];
        }
        while ( k-- ) {
            int b;
            cin >> b;
            add( i, b );
        }
    }

    for ( int i = 0; i < n; i++ )
        cout << h[ i ] << " ";
    cout << endl;


    dfs( 0, price );

    printf( "%.1f", sum );
    return 0;
}