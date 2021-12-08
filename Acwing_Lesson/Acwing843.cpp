
// 字符串哈希

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 字符串哈希的计算需要模 2^64 所以这里用 ull 可以通过溢出来取模
typedef unsigned long long ULL;

const int N = 100010;
// 这个就是 P 进制, 还可以选取 13331
// 但这个不是定死的, 仅仅是经验值
const int P = 131;

// h 数组是用来存储 字符串的前缀哈希
// p 数组是用来存储 p^n 次方的数据, 因为计算量大所以提前算好之后直接用
ULL h[ N ], p[ N ];

// 创建字符串哈希的数组
// 字符串哈希的核心就是将 字符串 设定成一个 p 进制的数字
void str_hash( string str ) {
    p[ 0 ] = 1;
    for ( int i = 1; i <= str.size(); i++ ) {
        h[ i ] = h[ i - 1 ] * P + str[ i - 1 ];
        p[ i ] = p[ i - 1 ] * P;
    }
}

// 参数是: 字符串的第一个下标和字符串的最后一个下标 => [l, r]
// 注意是闭区间
ULL get_hash( int l, int r ) {

    // 字符串哈希的计算公式
    return h[ r ] - h[ l - 1 ] * p[ r - ( l - 1 ) ];
}

int main() {
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    str_hash( str );
    for ( int i = 0; i < m; i++ ) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int str_hash1 = get_hash( a, b );
        int str_hash2 = get_hash( c, d );
        if ( str_hash1 == str_hash2 ) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}