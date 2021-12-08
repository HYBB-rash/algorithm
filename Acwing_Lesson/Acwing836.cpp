
// 并查集模板题目
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010;

int p[ N ];

// 查找集合的父节点
// 这里使用了压缩的优化, 让查找效率提升到几乎等于 0(1)
int find( int x ) {
    if ( p[ x ] != x ) p[ x ] = find( p[ x ] );
    return p[ x ];
}

// 将两个集合合并起来
void uni( int a, int b ) { p[ find( a ) ] = find( b ); }

int main() {

    int n, m;
    cin >> n >> m;

    for ( int i = 0; i <= n; i++ )
        p[ i ] = i;

    string op;
    for ( int i = 0; i < m; i++ ) {
        int a, b;
        cin >> op >> a >> b;
        if ( op == "M" )
            uni( a, b );
        else {
            if ( find( a ) == find( b ) )
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}