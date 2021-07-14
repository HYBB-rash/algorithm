
/** 
 * *  @File        :   Acwing3580.cpp
 * *  @Time        :   2021/05/28 14:08:39
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   Acwing 3580 每日一题
**/

#include <algorithm>
#include <iostream>

using namespace std;

const int N = 10010;
int q[N], n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    sort(q, q + n);
    int res = 0;
    for (int i = 0; i < n; i += 2) res += q[i + 1] - q[i];
    cout << res;
    return 0;
}