
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int N = 1010;

double A[ N ], B[ N ];

int main() {

    int k = 0;
    cin >> k;
    while ( k-- ) {
        int idx;
        double cof;
        cin >> idx >> cof;

        A[ idx ] = cof;
    }

    cin >> k;
    while ( k-- ) {
        int idx;
        double cof;
        cin >> idx >> cof;

        B[ idx ] = cof;
    }

    double C[ N ] = { 0 };
    vector<int> ans;
    for ( int i = 0; i < N; i++ ) {
        C[ i ] = A[ i ] + B[ i ];
        if ( C[ i ] != 0 ) ans.push_back( i );
    }

    cout << ans.size();
    for ( int i = ans.size() - 1; i >= 0; i-- ) {
        printf( " %d %.1f", ans[ i ], C[ ans[ i ] ] );
    }
    return 0;
}