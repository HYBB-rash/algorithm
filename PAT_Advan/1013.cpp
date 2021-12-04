#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

// 计算图的联通块 类型的题目

// 1013 题还有一个并查集解法
// 一会顺便复习一下
const int N = 1e6 + 10;

int e[ N ], ne[ N ], h[ N ], idx = 0;

void add( int a, int b ) { e[ idx ] = b, ne[ idx ] = h[ a ], h[ a ] = idx++; }

int n, m, k;
bool st[ N ] = { false };

void dfs( int idx ) {
    for ( int t = h[ idx ]; t != -1; t = ne[ t ] ) {
        int j = e[ t ];
        // cout << j << endl;
        if ( !st[ j ] ) {
            st[ j ] = true, dfs( j );
        }
    }
}

int get_connect( int idx ) {
    memset( st, 0, sizeof st );
    st[ idx ] = true;

    int cnt = 0;
    for ( int i = 1; i <= n; i++ ) {
        if ( st[ i ] ) continue;
        // cout << "dfs function" << endl;
        dfs( i );
        cnt++;
    }
    return cnt;
}

int main() {
    memset( h, -1, sizeof h );
    cin >> n >> m >> k;
    for ( int i = 0; i < m; i++ ) {
        int a, b;
        cin >> a >> b;
        add( a, b ), add( b, a );
    }

    for ( int i = 0; i < k; i++ ) {
        int query;
        cin >> query;
        cout << get_connect( query ) - 1 << endl;
    }
    return 0;
}