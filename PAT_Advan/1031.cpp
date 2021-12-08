#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main() {

    string str;
    cin >> str;
    int n = str.size();
    int n1, n2, n3;
    n1 = n3 = ( n + 2 ) / 3 - 1;
    n2      = n1 + ( n + 2 ) % 3 + 1;

    char chars[ 100 ][ 100 ];
    for ( int i = 0; i < 100; i++ ) {
        for ( int j = 0; j < 100; j++ ) {
            chars[i][j] = '@';
        }
    }
    int idx_x = 0, idx_y = 0, cnt = 0;
    for ( int i = 0; i < n1; i++ )
        chars[ idx_x++ ][ idx_y ] = str[ cnt++ ];
    // idx_x++;
    for ( int i = 0; i < n2; i++)
        chars[ idx_x ][ idx_y++ ] = str[ cnt++ ];
    idx_y-=1;
    for ( int i = 0; i < n3; i++ )
        chars[ --idx_x ][ idx_y ] = str[ cnt++ ];

    for ( int i = 0; i <= n1; i++ ) {
        for ( int j = 0; j < n2; j++ ) {
            if (chars[i][j] == '@') cout << " ";
            else cout << chars[i][j];
            // cout << chars[i][j] ;
        }
        cout << endl;
    }
    return 0;
}