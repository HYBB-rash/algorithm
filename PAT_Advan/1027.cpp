#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

char mapper( int num ) {
    if ( num >= 0 && num <= 9 ) return '0' + num;
    return 'A' + num - 10;
}

string convert( int num ) {
    string ans;
    do {
        ans.push_back( mapper( num % 13 ) );
        num /= 13;
    } while ( num );

    reverse( ans.begin(), ans.end() );
    if (ans.size() == 1) ans = '0' + ans;
    return ans;
}

int main() {

    int a, b, c;
    cin >> a >> b >> c;
    cout << '#' << convert( a ) << convert( b ) << convert( c ) << endl;
    return 0;
}