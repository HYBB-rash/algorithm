#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    scanf( "%d.%d.%d", &a, &b, &c );

    int x, y, z;
    scanf( "%d.%d.%d", &x, &y, &z );

    int res_a = 0, res_b = 0, res_c = 0;
    res_c += ( c + z ) % 29;
    res_b += ( c + z ) / 29 + b + y;
    res_a += res_b / 17 + a + x;
    res_b %= 17;

    printf( "%d.%d.%d", res_a, res_b, res_c );
    return 0;
}