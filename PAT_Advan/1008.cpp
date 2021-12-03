#include <algorithm>
#include <iostream>

using namespace std;


// 妈的, 被气死, 第一个数字居然是个数 n
// 我死活都手算不出答案, 奇了怪了, 结果第一个数字不是要求的楼层
// 操
int main() {

    int n, now = 0, a, sum = 0;
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> a;
        if ( a > now )
            sum += ( a - now ) * 6;
        else
            sum += ( now - a ) * 4;
        now = a;
        sum += 5;
    }

    cout << sum;
    return 0;
}