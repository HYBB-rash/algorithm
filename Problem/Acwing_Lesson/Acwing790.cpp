
/** 
 * *  @File        :   Acwing790.cpp
 * *  @Time        :   2021/05/28 14:00:24
 * *  @Author      :   hyong
 * *  @Version     :   1.0
 * *  @Contact     :   hyong_cs@outlook.com
 * !  @Description :   Acwing790 浮点数二分模板题目
**/

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    double num;
    cin >> num;
    double l = -1e9, r = 1e9;
    while ((r - l) > 1e-9) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= num) r = mid;
        else l = mid;
    }
    printf("%.6f", l);
    return 0;
}