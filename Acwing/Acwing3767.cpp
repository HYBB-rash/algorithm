
/*
 *  @File        :   Acwing3767.cpp
 *  @Time        :   2021/07/16 12:12:46
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   3767. 最小的值 Acwing 每日一题
 */

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 110;

int n;
int a[N], b[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < b[i])
            x++;
        else if (a[i] > b[i])
            y++;
    if (!y)
        puts("-1");
    else
        cout << (x + y) / y << endl;

    return 0;
}
