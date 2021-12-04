
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000010;

bool prime[ MAXN + 1 ];

// 打素数表
void init_prime() {
    prime[ 0 ] = prime[ 1 ] = true;
    for ( int i = 2; i <= MAXN; i++ ) {
        if ( !prime[ i ] )
            for ( int j = 2 * i; j < MAXN; j += i )
                prime[ j ] = true;
    }
}

// 进制转换
// 看看 yxc 的模板, 看看是我的好还是他的好
string convert( int num, int radix ) {
    string ans;
    do {
        int mod = num % radix;
        ans.push_back( mod + '0' );
        num /= radix;
    } while ( num );
    return ans;
}

int convert_10( string num, int radix ) {
    int ans = 0;
    for ( auto &c : num ) {
        ans *= radix;
        int n = c - '0';
        ans += n;
    }
    return ans;
}

int main() {
    init_prime();

    int number;
    while ( cin >> number ) {
        if ( number < 0 ) return 0;
        int radix = 0;
        cin >> radix;
        int rev = convert_10( convert( number, radix ), radix );
        if ( !prime[ rev ] && !prime[ number ] ) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}