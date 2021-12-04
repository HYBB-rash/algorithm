// 树的遍历 DFS 的应用
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6 + 10;

int e[ N ], ne[ N ], h[ N ], idx = 0;

void add( int a, int b ) { e[ idx ] = b, ne[ idx ] = h[ a ], h[ a ] = idx++; }

double price, rate;
int n;

double sum = 0;
int cnt    = 0;
void dfs( int idx, double cost ) {

    if ( h[ idx ] == -1 ) {
        if ( sum < cost ) {
            cnt = 1;
            sum = cost;
        } else if ( sum == cost )
            cnt++;
        return;
    }

    for ( int t = h[ idx ]; t != -1; t = ne[ t ] ) {
        int j = e[ t ];
        dfs( j, cost * ( 1.0 + 0.01 * rate ) );
    }
}

int main() {

    memset(h, -1, sizeof h);
    cin >> n >> price >> rate;

    int root = 0;
    for ( int i = 0; i < n; i++ ) {
        int b;
        cin >> b;
        if ( b != -1 ) add( b, i );
        else root = i;
    }

    dfs( root, price );
    // while (true);
    printf("%.2f %d", sum, cnt);
    return 0;
}