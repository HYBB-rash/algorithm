#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int N = 1e6 + 10;

int main() {
    vector<pair<int, double>> a, b;
    int n;

    cin >> n;
    while ( n-- ) {
        int eof;
        double cof;
        cin >> eof >> cof;
        a.push_back( { eof, cof } );
    }

    cin >> n;
    while ( n-- ) {
        int eof;
        double cof;
        cin >> eof >> cof;
        b.push_back( { eof, cof } );
    }

    // woc 浮点数组一定要初始化, 这里有坑 !!!
    double c[ N ] = { 0 };
    for ( int i = 0; i < a.size(); i++ ) {
        for ( int j = 0; j < b.size(); j++ ) {
            int eof    = a[ i ].first + b[ j ].first;
            double cof = a[ i ].second * b[ j ].second;
            c[ eof ] += cof;
        }
    }

    vector<int> non_zero;
    for ( int i = N - 1; i >= 0; i-- ) {
        if ( int( c[ i ] ) != 0 ) non_zero.push_back( i );
    }

    cout << non_zero.size();
    for ( int &idx : non_zero ) {
        printf( " %d %.1f", idx, c[ idx ] );
    }
    return 0;
}
