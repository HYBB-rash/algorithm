#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;

int main() {
    cin >> n;

    vector<string> list;
    getchar();
    int min_len = 0x3f3f3f3f;
    for ( int i = 0; i < n; i++ ) {
        string str;
        getline( cin, str );
        reverse( str.begin(), str.end() );
        list.push_back( str );
        min_len = min( (int) str.size(), min_len );
    }

    int idx = 0, flag = 0;
    for ( idx = 0; idx < min_len; idx++ ) {
        char init_char = list[ 0 ][ idx ];
        for ( int i = 1; i < list.size(); i++ ) {
            char cmp_char = list[ i ][ idx ];
            if ( init_char != cmp_char ) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
    }
    string ans = list[ 0 ].substr( 0, idx );
    reverse( ans.begin(), ans.end() );
    if (idx == 0) cout << "nai" << endl;
    else cout << ans << endl;

    return 0;
}